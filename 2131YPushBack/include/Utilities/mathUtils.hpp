#pragma once

#include <math.h>
#include <vector>
#include <numeric>

#define toDeg(rad) (rad * 180/M_PI)
#define toRad(deg) (deg * M_PI/180)

double wrapAngle(double angle, bool degrees = true);
double constrainAccel(double targetVelocity, double currentVelocity, double maxAccel);


/**
 * @brief Average any Set of Values
 * 
 * @tparam T 
 * @param averageValues 
 * @return T 
 */
template <typename T>
T average(std::vector<T> averageValues)
{
    T summation = std::accumulate(averageValues.begin(), averageValues.end(), 0.0);
    return summation / (averageValues.size());
}
