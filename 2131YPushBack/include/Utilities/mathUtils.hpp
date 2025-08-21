#pragma once

#include <math.h>
#include <vector>
#include <numeric>

#define toDeg(rad) (rad * 180/M_PI)
#define toRad(deg) (deg * M_PI/180)

#define metersToInches(meters) (meters*39.3701)
#define inchesToMeters(inches) (inches/39.3701)

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


struct Angle
{
    private:

        // Class Member Variables
        double angleValue;
        bool radians;

    public:

        // Class Constructor

        /**
         * @brief Construct a new Angle object
         * 
         * @param angleValue 
         */
        Angle(double angleValue);

        /**
         * @brief Construct a new Angle object
         * 
         * @param angleValue 
         * @param radians 
         */
        Angle(double angleValue, bool radians);


        // Class Methods

        double getDeg();
        double getRad();
        void setAngleDeg(double angleDeg);
        void setAngleRad(double angleRad);

};