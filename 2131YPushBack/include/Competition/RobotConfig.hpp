#pragma once

#include "Chassis/Odoms/GpsOdom.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "Utilities/Positioning.hpp"
#include "pros/rotation.hpp"
#include "Chassis/Odoms/DriveWheelOdom.hpp"

#define PROG_CHASSIS 0


extern Pose globalRobotPose;

extern pros::Controller mainController;

extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;
extern pros::adi::Pneumatics shovel;




namespace intakeMotors {
    extern pros::Motor front;
    extern pros::Motor top;
    extern pros::Motor back;

}



#ifdef PROG_CHASSIS

extern pros::Rotation verticalRotation;
extern pros::Rotation horizontalRotation;

#if GPS_ODOM


extern GpsOdom Odom;

#else
extern DriveWheelOdom Odom;


#endif

namespace chassisIMUs {
extern pros::Imu IMU1;
extern pros::Imu IMU2;
}

#else
extern DriveWheelOdom Odom;

#endif