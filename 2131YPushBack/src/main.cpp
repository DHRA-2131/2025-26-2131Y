#include "main.h"

#include "Competition/RobotConfig.hpp"





#include "Utilities/Logging.hpp"

#include "pros/misc.hpp"
#include <cmath>



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    log(logLocation::MAIN, "Program Started: Battery at %f%%", pros::battery::get_capacity());
    chassis.calibrate();


    //(Odom.isGpsConnected()) ? (log(logLocation::MAIN, "Odom is Connected, X: %f, Y: %f", Odom.getGpsPosition().getX(), Odom.getGpsPosition().getY())) : (log(logLocation::MAIN, "GPS is NOT Connected"));

    
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
    
    //chassis.turnToAbsoluteHeading(90);
  
    //chassis.driveToPoint(Point(10,10));
    
    while(true);

    

} //autonomous

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



#if !PROG_CHASSIS

void opcontrol() {
    log(logLocation::MAIN, "Op Control Started");

     Odom.startOdom();
      
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


        //If R1 Intake ALL
        //If R2 Reverse ALL

        //If L1, Outtake Top Only
        //If L2, Top roller spin opposite
        if (intakeButton.value())intake.set(intakeState::Forward);
        else if (reverseIntakeButton.value()) intake.set(intakeState::Reverse);
        else if (outtakeMid.value()) intake.set(intakeState::OuttakeMid);
        else if (outtakeTop.value()) intake.set(intakeState::OuttakeTop);
        else intake.set(intakeState::Stop);

        static bool shovelToggle = false;
        static bool prevShovel = false;
        shovelToggle = (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_B) && !prevShovel) ? !shovelToggle : shovelToggle;
        prevShovel = (mainController.get_digital(pros::E_CONTROLLER_DIGITAL_B));
        shovel.set_value(shovelToggle);

        //log(logLocation::MAIN, "GPS: x: %f, y: %f, Confidence: %f, Delta Confidence: %f", Odom.getGpsPosition().getX(), Odom.getGpsPosition().getY(), Odom.gpsConfidence(), Odom.gpsDeltaConfidence());
    

        pros::delay(21);
    } //Opcontrol While True
     
     
     

   
} //opcontrol()

#else
void opcontrol(){
     int leftY = mainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = mainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        // move the chassis with curvature drive
        chassis.arcade(leftY, rightX);
        // delay to save resources
        pros::delay(10);
}

#endif