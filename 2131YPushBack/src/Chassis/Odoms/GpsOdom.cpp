#include "Chassis/Odoms/GpsOdom.hpp"
#include "Utilities/AbstractOdom.hpp"
#include "Utilities/KalmanFilter.hpp"
#include "Utilities/mathUtils.hpp"
#include "pros/rtos.hpp"

GpsOdom::GpsOdom(AbstractOdom& BaseOdomClass, pros::GPS& Gps, KalmanFilter& XKalman, KalmanFilter& YKalman) : AbstractOdom(BaseOdomClass), m_gps(Gps), m_xKalman(XKalman), m_yKalman(YKalman), m_lastGpsPosition(0,0,0), m_gpsTask([=, this]{


    //Stop Odom from running untill called for 
    m_updateTask->suspend();
    m_gpsTask.suspend();

    while(true){
        
        // Iterate to Check GPS Update
        static int gpsIterator = 0;
        gpsIterator++;

        bool gpsConnected = m_gps.is_installed();

        // Check that GPS has Updated and is Accurate
        if (gpsIterator >= 12)
        {
            if ((fabs(m_gps.get_error()) < 0.1) && gpsConnected)
            {
                // Calculate Kalman Filter Position Approximation
                this->m_currentPose.mutex->take();
                m_currentPose.x = m_xKalman.calculateFilter(metersToInches(m_gps.get_position_x()), m_currentPose.x);
                m_currentPose.y = m_yKalman.calculateFilter(metersToInches(m_gps.get_position_y()), m_currentPose.y);
                this->m_currentPose.mutex->take();

                gpsIterator = 0;
            }
        }
    }
})
{}

void GpsOdom::startOdom(){
    m_updateTask->resume();
    m_gpsTask.resume();
}

void GpsOdom::stopOdom(){
    m_updateTask->suspend();
    m_gpsTask.suspend();
}

void GpsOdom::setPosition(Pose& newPose){
    this->m_currentPose.mutex->take();
    m_currentPose = newPose;
    this->m_currentPose.mutex->give();

}

GpsOdom::~GpsOdom(){
    delete m_updateTask;
    m_gpsTask.remove();
}


bool GpsOdom::m_gpsIsAccurate(){
    if (!m_gps.is_installed()) return false;
    double error = m_gps.get_error();
    if (error > 0.1) return false;
    if (error-m_prevGpsConfidence > 0.01) return false;

    /* If its too close too the wall */
    // Deadzone from purdue
    // https://wiki.purduesigbots.com/vex-electronics/vex-sensors/smart-port-sensors/vex-gps-sensor
    /* 13.5*2 = 27 ... 58.5" for radius, convert to meters... 1.49m */
   
    return true; 
}


/* GPS Debug Functions */
Pose GpsOdom::getGpsPosition(){
    static double lastTime = 0;
    if ((pros::millis() - lastTime) > 20) Pose{m_gps.get_position_x(), m_gps.get_position_y(), m_gps.get_heading()};
    return m_lastGpsPosition;
}

bool GpsOdom::isGpsConnected(){
    return m_gps.is_installed();
}

double GpsOdom::gpsConfidence(){
    return m_gps.get_error();
}

double GpsOdom::gpsDeltaConfidence(){
    double delta =  m_gps.get_error()- m_prevGpsConfidence;
    m_prevGpsConfidence = m_gps.get_error();
    return delta;
}

   