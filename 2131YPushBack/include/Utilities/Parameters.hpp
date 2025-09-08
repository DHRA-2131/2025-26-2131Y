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
    int settleExitRange = 1;
    int velocitySettleExitTime = 100;
    int velocitySettleExitRange = 100;

    double minSpeed = 0;
    double maxSpeed = 127; //Volts

    double maxAccel = -1; //Volts/S^2

    double lockAngleDistance = 12;

    bool stopDriving = true;
};

struct turningParameters{
     arcDirection arc = arcDirection::none;

     bool waitForCompletion = true;
     
     int settleExitTime = 100;
     int settleExitRange = 3;
     int velocitySettleExitTime = 100;
     int velocitySettleExitRange = 100;

     double minSpeed = 0;
     double maxSpeed = 127; //-127 - 127

     double maxAccel = -1; //Volts/S/S

     bool stopDriving = true;


};