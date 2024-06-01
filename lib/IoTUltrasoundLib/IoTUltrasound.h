#ifndef _IoTUltrasound
#define _IoTUltrasound
#include <Arduino.h>

/**
 * @brief calculate the distance of the object
 * @param duration wave duration
 * @return distance of the object
 */

long calculateDistance(long duration);

/**
 * @brief calculate if you can pak
 * @param distance of the object
 * @return true if free
*/
boolean parking(long distance);

#endif