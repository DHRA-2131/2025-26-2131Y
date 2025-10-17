#include "Chassis/Chassis.hpp"
#include "MotionControl/MotionHandler.hpp"

DriveBase::DriveBase()
{
   
}

DriveBase* DriveBase::instance(){
    static DriveBase s_instance;
    return &s_instance;
}

void DriveBase::init(pros::MotorGroup* Right, pros::MotorGroup* Left, void* Localizer/* Replace void* to reference to localizer object*/)
{
   m_rightMotors = Right;
   m_leftMotors = Left;
   m_localizer = Localizer;

   motionHandler = MotionHandler::instance();

   m_intialized = true;
}

void DriveBase::setMotors(int rightVoltage, int leftVoltage)
{
   m_rightMotors->move(rightVoltage);
   m_leftMotors->move(leftVoltage);
}

void DriveBase::setBraking(pros::motor_brake_mode_e brakeMode)
{
   m_rightMotors->set_brake_mode_all(brakeMode);
   m_leftMotors->set_brake_mode_all(brakeMode);
}

