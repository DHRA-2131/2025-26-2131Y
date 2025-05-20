#include "Utilities/Positioning.hpp"
#include "Utilities/mathUtils.hpp"


void Point::getDistanceTo(Point& otherPoint){
    //Pythagorean theorem
    sqrt(pow(otherPoint.y-this->y,2) + pow((otherPoint.x-this->y),2));
}

void Pose::getAngleTo(Point& otherPoint){

    //Calculate angle between two points
    double angle = toRad(std::atan2(otherPoint.y-this->y, otherPoint.x-this->x));
    
    //Error (wrapped between -180 and 180)
    double angle_error = wrapAngle(angle - this->theta);


}