#include "Utilities/ExitConditions.hpp"
#include "cmath"
#include "logging.hpp"

ExitCondition::ExitCondition(double settleError, double settleTime, double delayTime) : m_settleError(settleError), m_settleTime(settleTime), m_delayTime(delayTime)
{}

bool ExitCondition::canExit(double value){

    (std::fabs(value) < m_settleError) ? m_count++ : (m_count = 0);

    //log(logLocation::ExitConditions, "Count: %i", m_count);

   
    if (m_count*m_delayTime >= m_settleTime) return true;
    return false;
}