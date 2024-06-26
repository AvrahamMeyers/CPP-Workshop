#include <cmath>
#include "Point.h"

float Point::distance(int x_coordinate, int y_coordinate) {
	float distance; 

	int xdifference = x_coordinate - x_point;
	int ydifference = y_coordinate - y_point;

	float xsquared = xdifference * xdifference;
	float ysquared = ydifference * ydifference;

	distance = sqrt(xsquared + ysquared);	
	
	return distance;
}