#include "Utilities/ExitConditions.hpp"
#include "cmath"
#include "logging.hpp"
#include <cmath>

ExitCondition::ExitCondition(double settleError, double settleTime, double delayTime) : m_settleError(settleError), m_settleTime(settleTime), m_delayTime(delayTime), m_count(0)
{}

bool ExitCondition::canExit(double value){

    (std::fabs(value) < m_settleError) ? m_count++ : (m_count = 0);

    //if (std::fabs(value) < m_settleError) {m_count++; log(logLocation::ExitConditions, "Increasing m_count");} 
    //else  {m_count = 0; log(logLocation::ExitConditions, "Restting m_count");}

    log(logLocation::ExitConditions, "Count: %i, Actual Error: %f, %i", m_count, value, (std::fabs(value) < m_settleError));

   
    if (m_count*m_delayTime >= m_settleTime) {log(logLocation::ExitConditions, "Exiting True!");return true;}
    return false;
}