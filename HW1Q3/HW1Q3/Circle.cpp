#include "Circle.h"
#include <math.h>

int Circle::PointonCircle(Point point) {
	
	double distance; //using the distance formula to calculate the distance between the center and the point

	int pointX = point.getX(), pointY = point.getY(),
		centerX = center.getX(), centerY = center.getY();

	int xdifference = pointX - centerX; 
	int ydifference = pointY - centerY;

	double xsquared = pow(xdifference, 2.0);
	double ysquared = pow(ydifference, 2.0);


	distance = sqrt(xsquared + ysquared);

	if (distance == radius)
		return 0;
	else if (distance < radius)
		return -1;
	else if (distance > radius)
		return 1;	
}