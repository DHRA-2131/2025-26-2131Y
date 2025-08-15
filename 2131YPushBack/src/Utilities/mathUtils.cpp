#include "Utilities/mathUtils.hpp"

#include <algorithm>

double wrapAngle(double angle, bool degrees){
    if (degrees){
        //If angle is greater than 180 subtract 360 otherwise if angle is less than -180 add 360
        angle = (angle > 180) ? angle - 360 : ((angle < -180) ? angle + 360 : angle);
    }
    
    // Same but for rads
    else angle = (angle > (M_PI)) ? angle - (2 * M_PI) : ((angle < (-1 * M_PI)) ? angle + (2 * M_PI) : angle);
    
    return angle;
}

double  constrainAccel(double targetVelocity, double currentVelocity, double maxAccel){
    //If not max accel defined
    if (maxAccel == -1) return targetVelocity;

    double deltaVelocity = targetVelocity - currentVelocity;

    //Clamp by accel
    deltaVelocity = std::clamp(deltaVelocity, -maxAccel, maxAccel);
    
    return currentVelocity + deltaVelocity;

    
}


Angle::Angle(double angleValue) 
    : angleValue(angleValue), radians(false)
{}


Angle::Angle(double angleValue, bool radians)
    : angleValue(angleValue), radians(radians)
{}


double Angle::getDeg()
{
    if (!radians)
        return angleValue;
    else
        return angleValue * (180 / M_PI);
}


double Angle::getRad()
{
    if (radians)
        return angleValue;
    else
        return angleValue * (M_PI / 180);
}


void Angle::setAngleDeg(double angleDeg)
{
    angleValue = angleDeg;
    radians = false;
}


void Angle::setAngleRad(double angleRad)
{
    angleValue = angleRad;
    radians = true;
}
