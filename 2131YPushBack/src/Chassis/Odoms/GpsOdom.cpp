#include "Chassis/Odoms/GpsOdom.hpp"
#include "Utilities/AbstractOdom.hpp"
#include "Utilities/KalmanFilter.hpp"
#include "Utilities/mathUtils.hpp"

GpsOdom::GpsOdom(AbstractOdom& BaseOdomClass, pros::GPS& Gps, KalmanFilter& XKalman, KalmanFilter& YKalman) : AbstractOdom(BaseOdomClass), m_gps(Gps), m_xKalman(XKalman), m_yKalman(YKalman), m_gpsTask([=, this]{


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


/* GPS Debug Functions */
Pose GpsOdom::getGpsPosition(){
    return Pose{m_gps.get_position_x(), m_gps.get_position_y(), m_gps.get_heading()};
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

   