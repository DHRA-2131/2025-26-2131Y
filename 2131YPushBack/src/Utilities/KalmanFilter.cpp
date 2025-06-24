#include "Utilities/KalmanFilter.hpp"

KalmanFilter::KalmanFilter(const double MeasurementVariance, double EstimateVariance, const double ProcessNoiseVariance) : 
m_measurementVariance(MeasurementVariance),
m_processNoiseVariance(ProcessNoiseVariance),
m_estimateVariance(EstimateVariance)
{}


double KalmanFilter::calculateFilter(double MeasuredMean, double EstimateMean){

    // Covariance Extrapolation Equation. This accounts for noise in the system, (any disturbances in the system that could cause the estimate to be off). This adds a constant each iteration.
    m_estimateVariance += m_processNoiseVariance;

    // Kalman Gain Equation, calculates how much the estimate can be trusted versus the measurement 
    m_kalmanGain = m_estimateVariance / (m_estimateVariance + m_measurementVariance);

    //State Update Equation, updates the state based on a blend of the estimate and measurement based on how much it trusts one over the other 
    EstimateMean += m_kalmanGain * (MeasuredMean - EstimateMean);

    //Covariance Update Equation, updates the variance (trustworthiness) of the estimate 
    m_estimateVariance *= (1 - m_kalmanGain);

    return EstimateMean;
}