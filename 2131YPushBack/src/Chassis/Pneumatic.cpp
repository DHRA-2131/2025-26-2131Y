#include "Chassis/Pneumatic.hpp"


Pneumatic::Pneumatic(std::uint8_t port, bool startExtended, bool extendedIsLow)
    : pros::adi::Pneumatics(port, startExtended, extendedIsLow)
{}

void Pneumatic::set(Status desiredState){
    switch (desiredState){
        case Status::Retracted:
            retract();
            break;
        
        case Status::Extended:
            extend();
            break;
    }
}

std::ostream& operator<<(std::ostream& os, const Pneumatic& printPneumatic)
{
    os << "Pneumatic State: " << printPneumatic.is_extended();
    return os;
}


