#include "Utilities/ExitConditions.hpp"
#include "cmath"

ExitCondition::ExitCondition(double settleError, double settleTime, double delayTime) : m_settleError(settleError), m_settleTime(settleTime), m_delayTime(delayTime)
{}

bool ExitCondition::canExit(double value){

    (std::fabs(value) < m_settleError) ? m_count++ : (m_count = 0);
   
    if (m_count*m_delayTime >= m_settleTime) return true;
    return false;
}