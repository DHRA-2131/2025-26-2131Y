#pragma once


#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"

#include "pros/rotation.hpp"

#include "pros/adi.hpp"

#include "lemlib/chassis/chassis.hpp"
#define PROG_CHASSIS 1




extern pros::Controller mainController;

extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;
extern pros::adi::Pneumatics shovel;







#ifdef PROG_CHASSIS

extern pros::Rotation verticalRotation;
extern pros::Rotation horizontalRotation;



extern pros::Imu IMU;


extern lemlib::Chassis chassis;

#else


amespace intakeMotors {
    extern pros::Motor front;
    extern pros::Motor top;
    extern pros::Motor back;

}

extern Intake intake;


#endif