#include "Competition/RobotConfig.hpp"
#include "pros/misc.hpp"

pros::Controller mainController(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftDrive({18,19,8});
pros::MotorGroup rightDrive({-17,-20,-9});

