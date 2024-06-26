#include <iostream>
#include <math.h>
#include "Shape.h"

const float PI = 3.14;

//class Point implementation
Shape::Point::Point(int X, int Y) :x(X), y(Y) { }
Shape::Point::Point(const Point& p)
{
	x = p.getX();
	y = p.getY();
}
void Shape::Point::print()
{
	std::cout << '(' << x << ',' << y << ")\n";
}

//class Shape implementation
Shape::Shape() {
	numofPoints = 0;
	points = new Point[0];
}

Shape::Shape(int numofPoints) {
	this->numofPoints = numofPoints;
	points = new Point[numofPoints];
	std::cout << "Enter values of " << numofPoints << " points:\n";
	char skip;
	for (int i = 0; i < numofPoints; i++) {
		std::cin >> skip >> this->points[i].x
			>> skip >> this->points[i].y
			>> skip;
	}
}

Shape::Shape(const Shape& s) {
	this->numofPoints = s.numofPoints;
	delete this->points;
	this->points = new Point[s.numofPoints];
}

Shape::Shape(Shape&& s) {
	this->numofPoints = s.numofPoints;
	delete this->points;
	this->points = s.points;
	s.points = nullptr;
	s.numofPoints = 0;
}

Shape::~Shape() {
	delete[] this->points;
	this->points = nullptr;
}

std::ostream& operator<<(std::ostream& out, Shape& s) {
	out << "points: ";
	for (int i = 0; i < s.numofPoints; i++) {
		out << '(' << s.points[i].x << ',' 
			<< s.points[i].y << ')' << ' ';
	}
	return out;
}

//class Circle implementation
Circle::Circle(float radius) : Shape(1) {
	this->radius = radius;
}

float Circle::area() const {
	float area = (PI * pow(this->radius, 2));
	return area;
}

bool Circle::isSpecial() {
	if (this->points[0].x == 0 && this->points[0].y == 0)
		return true;
	else
		return false;
}

void Circle::printSpecial() const {
	std::cout << "A canonical circle with a radius "
		<< this->radius << std::endl;
}

//class Triangle implementation
Triangle::Triangle() : Shape(3) {} 

float Triangle::area() const {
	float sideA, sideB, sideC;
	//using the distance formula to calculate the distance between two points
	sideA = sqrt(pow((this->points[0].x - this->points[1].x), 2) + pow((this->points[0].y - this->points[1].y), 2));
	sideB = sqrt(pow((this->points[1].x - this->points[2].x), 2) + pow((this->points[1].y - this->points[2].y), 2));
	sideC = sqrt(pow((this->points[2].x - this->points[0].x), 2) + pow((this->points[2].y - this->points[0].y), 2));

	float halfPerim = (sideA + sideB + sideC) / 2;

	//using Heron's formula for calculating the area of a triangle
	float area = sqrt(halfPerim * (halfPerim - sideA) * (halfPerim - sideB) * (halfPerim - sideC));

	return area;
}

bool Triangle::isSpecial() {
	float sideA, sideB, sideC;

	sideA = sqrt(pow((this->points[0].x - this->points[1].x), 2) + pow((this->points[0].y - this->points[1].y), 2));
	sideB = sqrt(pow((this->points[1].x - this->points[2].x), 2) + pow((this->points[1].y - this->points[2].y), 2));
	sideC = sqrt(pow((this->points[2].x - this->points[0].x), 2) + pow((this->points[2].y - this->points[0].y), 2));
	if (sideA == sideB == sideC)
		return true;
	else
		return false;
}

void Triangle::printSpecial() const {
	std::cout << "An equilateral triangle with a side length of "
		<< sqrt(pow((this->points[0].x - this->points[1].x), 2) + pow((this->points[0].y - this->points[1].y), 2))
		<< std::endl;
}

//class Rectangle implementation
Rectangle::Rectangle() : Shape(4) {}

bool Rectangle::isSpecial() {
	float sideA, sideB;

	sideA = sqrt(pow((this->points[0].x - this->points[1].x), 2) + pow((this->points[0].y - this->points[1].y), 2));
	sideB = sqrt(pow((this->points[1].x - this->points[2].x), 2) + pow((this->points[1].y - this->points[2].y), 2));

	if (sideA == sideB)
		return true;
	else
		return false;
}

void Rectangle::printSpecial() const {
	std::cout << "Square with side length "
		<< sqrt(pow((this->points[0].x - this->points[1].x), 2) + pow((this->points[0].y - this->points[1].y), 2))
		<< std::endl;
}

float Rectangle::area() const {
	float sideA, sideB;

	sideA = sqrt(pow((this->points[0].x - this->points[1].x), 2) + pow((this->points[0].y - this->points[1].y), 2));
	sideB = sqrt(pow((this->points[1].x - this->points[2].x), 2) + pow((this->points[1].y - this->points[2].y), 2));

	float area;
	area = sideA * sideB;

	return area;
}
