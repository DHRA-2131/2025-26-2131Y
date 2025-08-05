#pragma once

enum class arcDirection{
    none,
    arcToLeft,
    arcToRight
};

struct drivingParameters{
    bool forward = true;
    bool waitForCompletion = true;

    int settleExitTime = 1;
    int settleExitRange = 0;
    int velocitySettleExitTime = 0;
    int velocitySettleExitRange = 0;

    double minSpeed = 0;
    double maxSpeed = 127; //Volts

    double maxAccel = 4; //Volts/S^2

    double lockAngleDistance = 5;

    bool stopDriving = true;
};

struct turningParameters{
     arcDirection arc = arcDirection::none;

     bool waitForCompletion = true;
     
     int settleExitTime = 1;
     int settleExitRange = 0;
     int velocitySettleExitTime = 0;
     int velocitySettleExitRange = 0;

     double minSpeed = 5;
     double maxSpeed = 127; //Volts

     double maxAccel = -1; //Volts/S/S

     bool stopDriving = true;


};