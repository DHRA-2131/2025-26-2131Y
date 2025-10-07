#include "Competition/RobotConfig.hpp"

#include "Chassis/DriveBase.hpp"
#include "Chassis/Odom.hpp"

#include "Chassis/Sensors/InertialSensor.hpp"
#include "Chassis/Sensors/MotorEncoder.hpp"

#include "Util/PIDController.hpp"
#include "Util/PIDController.hpp"


#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"



pros::Controller MainController(pros::E_CONTROLLER_MASTER);


namespace DriveMotors
{
    pros::MotorGroup rightMotors({1,2,3});
    pros::MotorGroup leftMotors({1,2,2});
}

namespace Odom
{   
    Pose robotPosition(0,0,0);

    InertialSensor dummyIMU(35);

    pros::MotorGroup dummyMotorGroup({35});
    MotorEncoder dummyMotorEncoder(dummyMotorGroup, 0,0,0);
    Odometry driveOdom(robotPosition, dummyMotorEncoder,dummyIMU);
    
}

namespace DrivePID
{
    PIDController lateralPID(0,0,0);
    PIDController angularPID(0,0,0);

}
DriveBase Chassis(DriveMotors::rightMotors, DriveMotors::leftMotors, Odom::driveOdom, DrivePID::lateralPID, DrivePID::angularPID, false);