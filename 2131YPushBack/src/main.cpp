#include "main.h"

#include "Chassis/ControllerInput.hpp"
#include "Chassis/Odoms/DriveWheelOdom.hpp"
#include "Chassis/Odoms/TrackingWheelOdom.hpp"
#include "Competition/RobotConfig.hpp"
#include "Chassis/Drive.hpp"
#include "Utilities/Logging.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include <cmath>
#include <ios>
// #include "Chassis/BrainScreen.hpp"





/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    log(logLocation::MAIN, "Program Started: Battery at %f%%", pros::battery::get_capacity());
    log(logLocation::MAIN, "Initializing... Calibrating IMU...");

    IMU.reset(true);
    log(logLocation::MAIN, "Imu Calibrated");




    

    //Logger<int>("TestVar", &test, 200);

    


    
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
    log(logLocation::MAIN, "Robot Disabled");
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
    log(logLocation::MAIN, "Connected to TM");

}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    // log(logLocation::MAIN, "Auton Started");
    // pros::Task autonTask = pros::Task([]{}); //Replace with auton task
    // pros::delay(14900); //Delay 14.5 seconds

    // autonTask.remove(); //Kill Auton Task
    // log(logLocation::MAIN, "Auton Killed!");
    
    // leftDrive.set_brake_mode(pros::MotorBrake::brake);
    // rightDrive.set_brake_mode(pros::MotorBrake::brake);

    // leftDrive.brake();
    // rightDrive.brake();

    

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


 #include "Chassis/Odoms/DriveWheelOdom.hpp"
 #include "Competition/RobotConfig.hpp"
 #include "Chassis/Intake.hpp"


void opcontrol() {
    log(logLocation::MAIN, "Op Control Started");
    
    
    
   //DriveWheelOdom Odom(globalRobotPose, IMU, leftDrive, rightDrive, 7, 3.25, 0.4115);
    TrackingWheelOdom Odom(globalRobotPose, verticalRotation, 1.25, horizontalRotation,8.125, 2, IMU);
    //chassis.driveToPoint(Point(0,24));
    chassis.turnToAbsoluteHeading(90);
   //while(true);

    
    //chassis.driveToPoint(Point(24, 0));
    /*
    
    const bool tank = false;   
    while(true){
    if (!tank){
    leftDrive.move(linearJoystick.value() + angularJoystick.value());
    rightDrive.move(linearJoystick.value() - angularJoystick.value());
    }
    else {
        leftDrive.move(tankLeftJoystick.value());
        rightDrive.move(tankRightJoystick.value());
    }

    if (intakeButton.value()) intake.set(intakeState::Forward);
    else if (outtakeButton.value()) intake.set(intakeState::Reverse);
    else intake.set(intakeState::Stop);

    
    */
     pros::delay(20);
    //}
     
     
     

   
}