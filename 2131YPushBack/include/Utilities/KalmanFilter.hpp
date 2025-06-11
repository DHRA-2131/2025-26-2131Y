#pragma once


class KalmanFilter
{
    private:

        // Class Member Variables
        const double m_measurementVariance;
        const double m_processNoiseVariance;

        double m_estimateVariance;
        double m_kalmanGain;

    
    public:

        KalmanFilter(const double MeasurementVariance, double EstimateVariance, const double ProcessNoiseVariance);

        double calculateFilter(double MeasuredMean, double EstimateMean);


};