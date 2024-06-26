#pragma once
#include <iostream>

class Shape {
public:
	class Point
	{
	public:
		int x;
		int y;
	public:
		//default constructor
		Point(int X = 0, int Y = 0);
		//copy constructor
		Point(const Point& p);
		int getX() const { return x; }
		int getY() const { return y; }
		void print();
	};

	//default constructor
	Shape();
	//constructor
	Shape(int numofPoints);
	//copy constructor
	Shape(const Shape& s);
	//move constructor
	Shape(Shape&& s);
	//virtual destructor
	virtual ~Shape();
	
	//pure virtual functions
	virtual float area() const = 0;
	virtual bool isSpecial() = 0;
	virtual void printSpecial() const = 0;

	friend std::ostream& operator<<(std::ostream& out, Shape& s);

protected:
	int numofPoints;
	Point* points;
};

class Circle : public Shape {
public:
	Circle(float radius);
	bool isSpecial() override;
	void printSpecial() const override;
	float area() const override;

private:
	float radius;
};

class Triangle : public Shape {
public:
	Triangle();
	bool isSpecial() override;
	void printSpecial() const override;
	float area() const override;
};

class Rectangle : public Shape {
public:
	Rectangle();
	bool isSpecial() override;
	void printSpecial() const override;
	float area() const override;
};
