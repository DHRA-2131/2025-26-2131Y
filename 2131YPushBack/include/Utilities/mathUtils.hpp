#pragma once

#include <math.h>


#define toDeg(rad) (rad * 180/M_PI)
#define toRad(deg) (deg * M_PI/180)

double wrapAngle(double angle, bool degrees = true);
double constrainAccel(double targetVelocity, double currentVelocity, double maxAccel);