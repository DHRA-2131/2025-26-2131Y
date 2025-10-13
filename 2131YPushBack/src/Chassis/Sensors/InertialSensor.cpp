#include "Chassis/Sensors/InertialSensor.hpp"
#include "Util/Constants.hpp"

InertialSensor::InertialSensor(uint8_t port)
    : pros::IMU(port), m_robotState(Eigen::Matrix3f::Zero())
{}


Eigen::Vector3f InertialSensor::getStateX() const
{
    return m_robotState.col(0);
}


Eigen::Vector3f InertialSensor::getStateY() const
{
    return m_robotState.col(1);
}


Eigen::Vector3f InertialSensor::getStateTheta() const
{
    return m_robotState.col(2);
}


Eigen::Matrix3f InertialSensor::getState() const
{
    return m_robotState;
}


void InertialSensor::update(float deltaTime)
{
    deltaTime *= millis_to_sec;
    m_robotState(2, 0) = static_cast<float>(this->get_accel().x) * gravity * meters_to_inches;
    m_robotState(2, 1) = static_cast<float>(this->get_accel().y) * gravity * meters_to_inches;
    m_robotState(0, 2) = static_cast<float>(this->get_heading());
    Eigen::Matrix3f stateUpdate;

    // [1.0f, dt  , (dt^2)/2]
    // [0.0f, 1.0f, dt      ]
    // [0.0f, 0.0f, 1.0f    ]
    stateUpdate << 1.0f, deltaTime, (deltaTime * deltaTime) / 2, 0.0f, 1.0f, deltaTime, 0.0f, 0.0f, 1.0f;

    // Update all values for each x, y, and theta
    // TODO Check that this Matrix Multiplication Works
    m_robotState = stateUpdate * m_robotState;
}

void InertialSensor::resetValues()
{
    m_robotState = Eigen::Matrix3f::Zero();
    this->set_heading(0);
}