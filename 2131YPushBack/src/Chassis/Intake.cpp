#include "Chassis/Intake.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/motor_group.hpp"


Intake::Intake(pros::MotorGroup& intakeMotors) : m_intakeMotors(intakeMotors)
{}

void Intake::set(intakeState state){
    switch(state){

        case intakeState::Stop:
            m_intakeMotors.set_brake_mode_all(pros::MotorBrake::brake);
            m_intakeMotors.move_voltage(0);
            break;
        
        case intakeState::Forward:
            m_intakeMotors.move_voltage(12000);
            break;
        
        case intakeState::Reverse:
            m_intakeMotors.move_voltage(-12000);
            break;

        default:
            m_intakeMotors.move_voltage(0); //Dont brake if something gets set weird, but stop
    }
}