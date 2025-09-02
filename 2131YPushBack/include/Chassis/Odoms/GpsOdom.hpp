#pragma once

#include "Utilities/AbstractOdom.hpp"
#include "Utilities/KalmanFilter.hpp"
#include "pros/gps.hpp"

class GpsOdom : public AbstractOdom{
    public:
        GpsOdom(AbstractOdom& BaseOdomClass, pros::GPS& Gps, KalmanFilter& XKalman, KalmanFilter& YKalman);
        ~GpsOdom();

        void startOdom() override;
        void stopOdom() override;

        void setPosition(Pose& newPose) override;

        Pose getGpsPosition();


        /* GPS Debug Functions*/
       
        bool isGpsConnected();
        double gpsConfidence();
        double gpsDeltaConfidence();

    
    private:
        pros::GPS& m_gps;
        KalmanFilter m_xKalman;
        KalmanFilter m_yKalman;

        pros::Task m_gpsTask;

        double m_prevGpsConfidence;
        Pose m_lastGpsPosition;


        bool m_gpsIsAccurate();


};