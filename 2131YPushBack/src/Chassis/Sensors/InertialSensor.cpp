#include "Chassis/Sensors/InertialSensor.hpp"

InertialSensor::InertialSensor(uint8_t port)
    : pros::Imu(port)
{}

Angle InertialSensor::angle(){
    return Angle(get_heading());
}