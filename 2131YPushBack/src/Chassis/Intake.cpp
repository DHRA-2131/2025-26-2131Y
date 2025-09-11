#include "Chassis/Intake.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/motor_group.hpp"
#include "Competition/RobotConfig.hpp"

Intake::Intake(pros::Motor& intakemotor1, pros::Motor& intakemotor2, pros::Motor& intakemotor3) : m_intakeFront(intakemotor1), m_intakeTop(intakemotor2), m_intakeBack(intakemotor3)
{}

void Intake::set(intakeState state){
    switch(state){

        case intakeState::Stop:
            //m_intakeFront.set_brake_mode(pros::MotorBrake::brake);
            //m_intakeTop.set_brake_mode(pros::MotorBrake::brake);
            m_intakeFront.move(0);
            m_intakeTop.move(0);
            m_intakeBack.move(0);
            break;
        
        case intakeState::Forward:
            m_intakeFront.move(127);
            m_intakeTop.move(127);
            m_intakeBack.move(127);
            break;
        
        case intakeState::Reverse:
            m_intakeFront.move(-127);
            m_intakeTop.move(-127);
            m_intakeBack.move(-127);
            break;

        case intakeState::OuttakeMid:
            m_intakeFront.move(127);
            m_intakeTop.move(-127);
            m_intakeBack.move(-127);
            break;
        
        case intakeState::OuttakeTop:
            m_intakeFront.move(127);
            m_intakeTop.move(127);
            m_intakeBack.move(-127);
            break;
            

        default:
            m_intakeFront.move(0);
            m_intakeTop.move(0);
            m_intakeBack.move(0); //Dont brake if something gets set weird, but stop
    }
}
