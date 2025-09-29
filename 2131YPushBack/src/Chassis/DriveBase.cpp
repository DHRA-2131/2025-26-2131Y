#include "Chassis/DriveBase.hpp"
#include "Competition/RobotConfig.hpp"

DriveBase::DriveBase(pros::MotorGroup& rightDrive, pros::MotorGroup& leftDrive, Odometry& robotOdom, PIDController& lateralPID, PIDController& angularPID, bool inMotion, ControlMethods driveControl = ControlMethods::ArcadeDrive, int joystickDeadZone = 10)
    : m_rightDrive(rightDrive), m_leftDrive(leftDrive), m_robotOdom(robotOdom), m_lateralPID(lateralPID), m_angularPID(angularPID), m_inMotion(inMotion), m_driveControl(driveControl), m_joystickDeadZone(joystickDeadZone)
{}


void DriveBase::driveControl()
{
    if (m_driveControl == ControlMethods::ArcadeDrive)
    {
        
    }
    else if (m_driveControl == ControlMethods::TankDrive)
    {
        int32_t rightOutput = MainController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        int32_t leftOutput = MainController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);

        rightOutput = (fabs(rightOutput) > m_joystickDeadZone) ? rightOutput : 0;
        leftOutput = (fabs(leftOutput) > m_joystickDeadZone) ? leftOutput : 0;

        m_rightDrive.move(rightOutput);
        m_leftDrive.move(leftOutput);
    }
}


void DriveBase::driveToPoint(Point& targetPoint, driveToPointSettings drivingParams = {})
{

}


void DriveBase::turnToPoint(Point& targetPoint, turnToPointSettings turnParams = {})
{

}


void DriveBase::turnToHeading(float targetHeading, turnToHeadingSettings turnParams = {})
{

}


void DriveBase::delayUntilMovementsEnd() const
{

}
