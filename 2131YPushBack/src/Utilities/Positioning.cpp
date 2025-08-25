#include "Utilities/Positioning.hpp"
#include "Utilities/mathUtils.hpp"
#include "pros/rtos.hpp"


Point::Point(double x, double y) : x(x), y(y), mutex(std::make_shared<pros::Mutex>())
{
    
}

Pose::Pose(double x, double y, double theta) : Point(x, y), theta(theta)
{}

double Point::getX(){
    mutex->take();
    double x = this->x;
    mutex->give();
    return x;
}

double Point::getY(){
     mutex->take();
    double y = this->y;
    mutex->give();
    return y;
}

double Point::getDistanceTo(Point& otherPoint){
    //Pythagorean theorem
    mutex->lock();
    return sqrt(pow(otherPoint.getY()-this->y,2) + pow((otherPoint.getX()-this->x),2));
    mutex->give();
    
}

double Pose::getAngleTo(Point& otherPoint){

    //Calculate angle between two points
    mutex->lock();
    double angle = toDeg(std::atan2(otherPoint.getX()-this->x, otherPoint.getY()-this->y));
    mutex->give();


    
    //Error (wrapped between -180 and 180)
    return wrapAngle(angle - this->theta);


}