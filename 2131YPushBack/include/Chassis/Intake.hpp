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

        Intake(pros::MotorGroup& intakeMotors);


        /**
        * @brief Set Intake's Rotation
        *
        * @param state
        */
        void set(intakeState state);

    private:
        pros::MotorGroup& m_intakeMotors;

};

extern Intake intake;