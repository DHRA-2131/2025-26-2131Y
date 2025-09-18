#include "Chassis/Pneumatic.hpp"

#include "pros/adi.hpp"


Pneumatic(std::uint8_t port, bool startExtended, bool extendedIsLow = false)
    : pros::adi::Pneumatics(port, startExtended, extendedIsLow)
{}



void Pneumatic::set(bool state)
{   
    m_state = (m_inverted) ? !state : state; //Adjust for inversion
    pros::c::adi_digital_write(m_port, m_state);

}

bool Pneumatic::get()
{
    return (m_inverted) ? !m_state : m_state; //Adjust to correct for inversion
}

void Pneumatic::toggle()
{
    m_state != m_state;
    pros::c::adi_digital_write(m_port, m_state);
}

std::ostream& operator<<(std::ostream& os, const Pneumatic& printPneumatic)
{
    os << printPneumatic.m_state;
    return os;
}


