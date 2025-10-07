#include "Chassis/Odom.hpp"

Odometry::Odometry(Pose robotPosition, AbstractEncoder& encoder, InertialSensor& inertial)
    : m_robotPosition(robotPosition),
    m_encoder(encoder),
    m_inertial(inertial),
    m_calculatePosition(pros::Task([]{}))
{}