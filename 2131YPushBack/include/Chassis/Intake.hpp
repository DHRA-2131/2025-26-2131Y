#pragma once


#include "pros/motor_group.hpp"
#include "pros/motor_group.hpp"

enum class intakeState
{
    Stop,
    Forward,
    Reverse,
    OuttakeMid,
    OuttakeTop
};


class Intake
{   
    
    public:

        /** 
        * @brief Intake Constructor
        *
        * @param intakeMotors
        */

        Intake(pros::Motor& intakemotor1, pros::Motor& intakemotor2, pros::Motor& intakemotor3);


        /**
        * @brief Set Intake's Rotation
        *
        * @param state
        */
        void set(intakeState state);

    private:
        pros::Motor& m_intakemotor1;
        pros::Motor& m_intakemotor2;
        pros::Motor& m_intakemotor3;

};

extern Intake intake;