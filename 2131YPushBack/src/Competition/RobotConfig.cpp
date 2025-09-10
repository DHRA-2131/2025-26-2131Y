#include "Competition/RobotConfig.hpp"

#include "lemlib/chassis/chassis.hpp"
#include "pros/misc.hpp"

#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
#include "pros/adi.hpp"
#include <cstddef>




pros::Controller mainController(pros::E_CONTROLLER_MASTER);







#if  PROG_CHASSIS
pros::MotorGroup leftDrive({-10, -21, -15}); //-16,-17,-19 for actual robot - -10,-21, -15 for drivebase
pros::MotorGroup rightDrive({16, 20, 13}); //14, 2, 1 - 16, 20, 13

pros::IMU IMU(0);

lemlib::Drivetrain drive(&leftDrive, &rightDrive, 11, 3.25, 450, 8);

lemlib::ControllerSettings linearController(10, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            3, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);


lemlib::ControllerSettings angularController(2, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             10, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

// sensors for odometry
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel
                            nullptr, // vertical tracking wheel 2, set to nullptr as we don't have a second one
                            nullptr, // horizontal tracking wheel
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &IMU // inertial sensor
);


// create the chassis
lemlib::Chassis chassis(drive, linearController, angularController, sensors, &throttleCurve, &steerCurve);

#else 

pros::MotorGroup leftDrive({-16, -17, -19}); //-16,-17,-19 for actual robot - -10,-21, -15 for drivebase
pros::MotorGroup rightDrive({14, 2, 1}); //14, 2, 1 - 16, 20, 13



pros::Imu IMU(8);

namespace intakeMotors{
    pros::Motor front(9);
    pros::Motor top(4);
    pros::Motor back(-10);
}


pros::adi::Pneumatics shovel('a', false);

#endif

