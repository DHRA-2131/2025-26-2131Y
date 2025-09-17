#include "Chassis/Pnumatic.cpp"

#include "pros/adi.h"

Pnumatic::Pnumatic(uint8_t port, const bool inverted)
    : m_port(port), m_inverted(inverted), m_state(false)
{}

void Pnumatic::init()
{
    pros::c::adi_port_set_config(port, pros::E_ADI_ANALOG_OUT);
}

void Pnumatic::set(bool state)
{   
    m_state = (inverted) ? !state : state; //Adjust for inversion
    pros::c::adi_digital_write(m_port, m_state);

}

void Pnumatic::get()
{
    return (inverted) ? !m_state : m_state; //Adjust to correct for inversion
}

void Pnumatic::toggle()
{
    m_state != m_state;
    pros::c::adi_digital_write(m_port, m_state);
}

std::ostream& operator<<(std::ostream& os, const Pnumatic& printPnumatic)
{
    os << printPnumatic.m_state;
    return os;
}


