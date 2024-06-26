#pragma once
#include "Point.h"

const float PI = 3.14;

class Circle {
	Point center;
	int radius;

public:
	void setcenter(int x, int y) { center.setX(x); center.setY(y); }
	void setradius(int r) { radius = r; }
	Point getcenter() { return center; }
	int getradius() { return radius; }

	float Area() { return PI * radius * radius; }
	float Circumference() { return 2 * PI * radius; }
	int PointonCircle(Point point);
};