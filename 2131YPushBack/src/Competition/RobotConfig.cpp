#include "Competition/RobotConfig.hpp"
#include "pros/misc.hpp"

pros::Controller mainController(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftDrive({-18,-16,-10});
pros::MotorGroup rightDrive({15,14,1});

