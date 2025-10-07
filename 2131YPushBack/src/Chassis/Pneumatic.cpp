#include "Chassis/Pneumatic.hpp"
#include "Competition/RobotConfig.hpp"


Pneumatic::Pneumatic(pros::controller_digital_e_t controllerButton, std::uint8_t port, bool startExtended, bool extendedIsLow)
    : m_controllerButton(controllerButton), pros::adi::Pneumatics(port, startExtended, extendedIsLow)
{}

void Pneumatic::set(Status desiredState)
{
    switch (desiredState){
        case Status::Retracted:
            retract();
            break;
        
        case Status::Extended:
            extend();
            break;
    }
}

void Pneumatic::driveControl()
{
    this->set(static_cast<Status>(MainController.get_digital(m_controllerButton)));
}

std::ostream& operator<<(std::ostream& os, const Pneumatic& printPneumatic)
{
    os << "Pneumatic State: " << printPneumatic.is_extended();
    return os;
}

Pneumatic shovelMech(pros::E_CONTROLLER_DIGITAL_Y, 'A', false);


