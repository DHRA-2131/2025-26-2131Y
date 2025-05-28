#include "Competition/RobotConfig.hpp"
#include "pros/misc.hpp"

pros::Controller mainController(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftDrive({1,2,3});
pros::MotorGroup rightDrive({4,5,6});

