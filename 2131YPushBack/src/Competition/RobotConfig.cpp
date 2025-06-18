#include "Competition/RobotConfig.hpp"
#include "pros/misc.hpp"
#include "Utilities/Positioning.hpp"

Pose robotPose(0,0,0);

pros::Controller mainController(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftDrive({16,17,20});
pros::MotorGroup rightDrive({-14,-13,-11});

pros::Imu IMU(17);

