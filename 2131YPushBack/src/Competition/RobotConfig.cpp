#include "Competition/RobotConfig.hpp"
#include "pros/misc.hpp"

pros::Controller mainController(pros::E_CONTROLLER_MASTER);

pros::MotorGroup leftDrive({16,17,20});
pros::MotorGroup rightDrive({-14,-13,-11});

