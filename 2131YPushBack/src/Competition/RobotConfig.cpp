#include "Competition/RobotConfig.hpp"
#include "pros/misc.hpp"
#include "Utilities/Positioning.hpp"
#include "pros/motor_group.hpp"

Pose globalRobotPose(0,0,0);

pros::Controller mainController(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftDrive({-16, -17, -19});
pros::MotorGroup rightDrive({14, 2, 1});

pros::Imu IMU(17);

pros::MotorGroup intakeGroup({-10, 9});

