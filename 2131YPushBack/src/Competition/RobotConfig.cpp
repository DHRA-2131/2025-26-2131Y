#include "Competition/RobotConfig.hpp"

#include "pros/misc.hpp"
#include "Utilities/Positioning.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"


Pose globalRobotPose(0,0,0);

pros::Controller mainController(pros::E_CONTROLLER_MASTER);





namespace intakeMotors{
    pros::Motor front(9);
    pros::Motor top(4);
    pros::Motor back(-10);
}


#if  PROG_CHASSIS
pros::MotorGroup leftDrive({-10, -21, -15}); //-16,-17,-19 for actual robot - -10,-21, -15 for drivebase
pros::MotorGroup rightDrive({16, 20, 13}); //14, 2, 1 - 16, 20, 13

namespace chassisIMUs{
pros::IMU IMU1(17);
pros::IMU IMU2(21);
}

/* Robot Testing Chassis */
pros::Rotation verticalRotation(-18);
pros::Rotation horizontalRotation(-9);

DriveWheelOdom Odom(globalRobotPose, chassisIMUs::IMU1, leftDrive, rightDrive, 7, 3.25, 0.4115);

#else

pros::MotorGroup leftDrive({-16, -17, -19}); //-16,-17,-19 for actual robot - -10,-21, -15 for drivebase
pros::MotorGroup rightDrive({14, 2, 1}); //14, 2, 1 - 16, 20, 13
pros::Imu IMU(8);

DriveWheelOdom Odom(globalRobotPose, IMU, leftDrive, rightDrive, 7, 3.25, 0.4115);
#endif

