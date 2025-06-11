#pragma once


#include "pros/motor_group.hpp"
#include "pros/motor_group.hpp"

enum class intakeState
{
    Stop,
    Forward,
    Reverse
};


class Intake
{   
    
    public:

        Intake(pros::MotorGroup& intakeMotors);

        void set(intakeState state);

    private:
        pros::MotorGroup& m_intakeMotors;

};