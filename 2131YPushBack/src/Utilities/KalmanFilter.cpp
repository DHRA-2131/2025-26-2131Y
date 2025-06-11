#include "Utilities/KalmanFilter.hpp"

KalmanFilter::KalmanFilter(const double MeasurementVariance, double EstimateVariance, const double ProcessNoiseVariance) : 
m_measurementVariance(MeasurementVariance),
m_processNoiseVariance(ProcessNoiseVariance),
m_estimateVariance(EstimateVariance)
{}


double KalmanFilter::calculateFilter(double MeasuredMean, double EstimateMean){

    //
    m_estimateVariance += m_processNoiseVariance;

    //
    m_kalmanGain = m_estimateVariance / (m_estimateVariance + m_measurementVariance);

    //
    EstimateMean += m_kalmanGain * (MeasuredMean - EstimateMean);

    //
    m_estimateVariance *= (1 - m_kalmanGain);

    return EstimateMean;
}