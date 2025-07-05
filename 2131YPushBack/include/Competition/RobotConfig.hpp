#pragma once

#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "Utilities/Positioning.hpp"
#include "pros/rotation.hpp"


extern Pose globalRobotPose;

extern pros::Controller mainController;

extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;

extern pros::Imu IMU;

extern pros::MotorGroup intakeGroup;

extern pros::Rotation verticalRotation;