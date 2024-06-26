#pragma once
#include "Point.h"

class Polygon{
	int vertexcount;
	Point* vertices;

public:
	Polygon(int number_of_vertices);//constructor
	Polygon(const Polygon& P);//copy constructor
	~Polygon();//destructor

	void addPoint(Point vertex, int index);
	float perimeter();
	bool polygon_check(Polygon received);

	Point* get_vertices() { return vertices; }
};