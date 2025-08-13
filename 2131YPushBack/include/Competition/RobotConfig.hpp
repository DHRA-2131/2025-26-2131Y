#pragma once

#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "Utilities/Positioning.hpp"
#include "pros/rotation.hpp"

#define PROG_CHASSIS 0


extern Pose globalRobotPose;

extern pros::Controller mainController;

extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;

extern pros::Imu IMU;


namespace intakeMotors {
    extern pros::Motor front;
    extern pros::Motor top;
    extern pros::Motor back;

}

#ifdef PROG_CHASSIS

extern pros::Rotation verticalRotation;
extern pros::Rotation horizontalRotation;

#endif