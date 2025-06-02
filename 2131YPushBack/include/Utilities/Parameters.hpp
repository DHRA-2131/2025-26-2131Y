#pragma once

enum class arcDirection{
    none,
    arcToLeft,
    arcToRight
};

struct drivingParameters{
    bool forward = true;
    bool waitForCompletion = true;

    int settleExitTime = 0;
    int settleExitRange = 0;
    int velocitySettleExitTime = 0;
    int velocitySettleExitRange = 0;

    double minSpeed = 0;
    double maxSpeed = 12; //Volts

    double maxAccel = 0; //Volts/S/S

    double lockAngleDistance = 0;

    bool stopDriving = true;
};

struct turningParameters{
     arcDirection arc = arcDirection::none;

     bool waitForCompletion = true;
     
     int settleExitTime = 0;
     int settleExitRange = 0;
     int velocitySettleExitTime = 0;
     int velocitySettleExitRange = 0;

     double minSpeed = 0;
     double maxSpeed = 12; //Volts

     double maxAccel = 0; //Volts/S/S

     bool stopDriving = true;


};