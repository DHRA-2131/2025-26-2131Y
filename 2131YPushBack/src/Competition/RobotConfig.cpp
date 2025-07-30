#include "Competition/RobotConfig.hpp"
#include "pros/misc.hpp"
#include "Utilities/Positioning.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"

Pose globalRobotPose(0,0,0);

pros::Controller mainController(pros::E_CONTROLLER_MASTER);



pros::Imu IMU(17);

pros::MotorGroup intakeGroup({11, 9, 4});


#ifdef PROG_CHASSIS
pros::MotorGroup leftDrive({-10, -21, -15}); //-16,-17,-19 for actual robot - -10,-21, -15 for drivebase
pros::MotorGroup rightDrive({16, 20, 13}); //14, 2, 1 - 16, 20, 13

/* Robot Testing Chassis */
pros::Rotation verticalRotation(-18);
pros::Rotation horizontalRotation(-9);

#else
pros::MotorGroup leftDrive({-16, -17, -19}); //-16,-17,-19 for actual robot - -10,-21, -15 for drivebase
pros::MotorGroup rightDrive({14, 2, 1}); //14, 2, 1 - 16, 20, 13
#endif

