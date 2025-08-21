#include "Chassis/Odoms/GpsOdom.hpp"
#include "Utilities/AbstractOdom.hpp"
#include "Utilities/KalmanFilter.hpp"
#include "Utilities/mathUtils.hpp"

GpsOdom::GpsOdom(AbstractOdom& BaseOdomClass, pros::GPS& Gps, KalmanFilter& XKalman, KalmanFilter& YKalman) : AbstractOdom(BaseOdomClass), m_gps(Gps), m_xKalman(XKalman), m_yKalman(YKalman), m_gpsTask([=, this]{


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
            m_currentPose.x = m_xKalman.calculateFilter(metersToInches(m_gps.get_position_x()), m_currentPose.x);
            m_currentPose.y = m_yKalman.calculateFilter(metersToInches(m_gps.get_position_y()), m_currentPose.y);

            gpsIterator = 0;
        }
    }

})
{}

void GpsOdom::startOdom(){
    m_updateTask.resume();
}

void GpsOdom::stopOdom(){
    m_updateTask.suspend();
}

void GpsOdom::setPosition(Pose& newPose){
    m_currentPose = newPose;
}


   