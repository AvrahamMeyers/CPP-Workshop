#pragma once

class Point {
	int x_point;
	int y_point;

public:
	Point(int x, int y) : x_point(x), y_point(y) {}; //using a constructor to initialize a Point
	
	Point() : x_point(0), y_point(0) {};
	Point(const Point& other) : x_point(other.x_point), y_point(other.y_point) {};

	float distance(int x_coordinate, int y_coordinate);

	void set_X(int x) { x_point = x; }
	void set_y(int y) { y_point = y; }
	int get_x() { return x_point; }
	int get_y() { return y_point; }
};