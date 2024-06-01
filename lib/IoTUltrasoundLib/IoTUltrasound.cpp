#include <IoTUltrasound.h>

long calculateDistance(long duration)
{
    long distance;
    distance = (duration / 2) / 29.1;
    
    return distance;
}

boolean parking(long distance){
    if(distance < 50)
        return false;
    return true;
}