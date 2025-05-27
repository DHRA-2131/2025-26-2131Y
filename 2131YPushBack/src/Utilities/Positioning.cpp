#include "Utilities/Positioning.hpp"
#include "Utilities/mathUtils.hpp"


Point::Point(double x, double y) : x(x), y(y)
{}

Pose::Pose(double x, double y, double theta) : Point(x, y), theta(theta)
{}

double Point::getDistanceTo(Point& otherPoint){
    //Pythagorean theorem
    return sqrt(pow(otherPoint.y-this->y,2) + pow((otherPoint.x-this->y),2));
    
}

double Pose::getAngleTo(Point& otherPoint){

    //Calculate angle between two points
    double angle = toRad(std::atan2(otherPoint.y-this->y, otherPoint.x-this->x));
    
    //Error (wrapped between -180 and 180)
    return wrapAngle(angle - this->theta);


}