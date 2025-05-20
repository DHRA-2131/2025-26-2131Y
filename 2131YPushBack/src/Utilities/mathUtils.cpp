#include "Utilities/mathUtils.hpp"

double wrapAngle(double angle, bool degrees){
    if (degrees){
        //If angle is greater than 180 subtract 360 otherwise if angle is less than -180 add 360
        angle = (angle > 180) ? angle - 360 : ((angle < -180) ? angle + 360 : angle);
    }
    
    // Same but for rads
    else angle = (angle > (2 * M_PI)) ? angle - (4 * M_PI) : ((angle < (-2 * M_PI)) ? angle + (4 * M_PI) : angle);
    
    return angle;
}