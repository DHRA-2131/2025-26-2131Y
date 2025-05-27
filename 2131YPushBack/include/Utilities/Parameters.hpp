#pragma once

enum class arcDirection{
    none,
    arcToLeft,
    arcToRight
};

struct turningParameters{
    arcDirection arc = arcDirection::none;
     int settleExitTime = 0;
     int settleExitRange = 0;
     int velocitySettleExitTime = 0;
     int velocitySettleExitRange = 0;

     double minSpeed = 0;
     double maxSpeed = 12; //Volts

     double maxAccel = 0; //Volts/S/S

     bool stopDriving = true;


};