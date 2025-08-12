#include "Chassis/Intake.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/motor_group.hpp"
#include "Competition/RobotConfig.hpp"

Intake::Intake(pros::Motor& intakemotor1, pros::Motor& intakemotor2, pros::Motor& intakemotor3) : m_intakemotor1(intakemotor1), m_intakemotor2(intakemotor2), m_intakemotor3(intakemotor3)
{}

void Intake::set(intakeState state){
    switch(state){

        case intakeState::Stop:
            //m_intakemotor1.set_brake_mode(pros::MotorBrake::brake);
            //m_intakemotor2.set_brake_mode(pros::MotorBrake::brake);
            m_intakemotor1.move(0);
            m_intakemotor2.move(0);
            m_intakemotor3.move(0);
            break;
        
        case intakeState::Forward:
            m_intakemotor1.move(127);
            m_intakemotor2.move(127);
            m_intakemotor3.move(127);
            break;
        
        case intakeState::Reverse:
            m_intakemotor1.move(-127);
            m_intakemotor2.move(-127);
            m_intakemotor3.move(-127);
            break;

        case intakeState::OuttakeMid:
            m_intakemotor1.move(127);
            m_intakemotor2.move(-127);
            m_intakemotor3.move(-127);
            break;
        
        case intakeState::OuttakeTop:
            m_intakemotor1.move(127);
            m_intakemotor2.move(127);
            m_intakemotor3.move(-127);
            break;
            

        default:
            m_intakemotor1.move(0);
            m_intakemotor2.move(0);
            m_intakemotor3.move(0); //Dont brake if something gets set weird, but stop
    }
}
pros::Motor motor1(9);
pros::Motor motor2(4);
pros::Motor motor3(-10);
Intake intake(motor1, motor2, motor3);