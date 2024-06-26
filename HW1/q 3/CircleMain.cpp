/*
CircleMain.cpp
Accepts values for three circles, and dislpays their area and circumcerence,
then accepts values for points and displays how many of the entered points are on or within the three circles
CPP Workshop
Homework 1 Question 3
Avraham Meyers
Created and Modified on 3.9.21
*/

#include <iostream>
#include "Circle.h"
using namespace std;

void setCircle(Circle& c);
//given a Circle, sets the values that are entered on the console as the values for the Circle
void setPoint(Point& p);
//given a Point, sets the values that are entered on the console as the values for the Point

int main() {
	Circle A, B, C;

	cout << "enter the center point and radius of 3 circles:\n";
	
	setCircle(A);
	setCircle(B);
	setCircle(C);

	cout << "perimeter:\t"
		<< "A: " << A.Circumference() << '\t'
		<< "B: " << B.Circumference() << '\t'
		<< "C: " << C.Circumference() << endl;
	cout << "area:\t"
		<< "A: " << A.Area() << '\t'
		<< "B: " << B.Area() << '\t'
		<< "C: " << C.Area() << endl;

	cout << "enter points until (0,0):\n";

	int onA(0), onB(0), onC(0);

	Point p;
	setPoint(p);
	while (p.getX() != 0 || p.getY() != 0) { //if the Point entered has a value of (0,0)
											// end the loop
		if (A.PointonCircle(p) != 1)
			onA++;
		if (B.PointonCircle(p) != 1)
			onB++;
		if (C.PointonCircle(p) != 1)
			onC++;

		setPoint(p);
	}

	cout << "num of points in circle:\t"
		<< "A:" << onA << '\t'
		<< "B:" << onB << '\t'
		<< "C:" << onC << endl;

	return 0;
}

void setCircle(Circle& c) {
	char skip;
	int x, y, radius;
	cin >> skip >> x >> skip //using a char to skip the parentheses and comma
		>> y >> skip >> radius;

	c.setcenter(x, y);
	c.setradius(radius);
}

void setPoint(Point& p) {
	char skip;
	int x, y;
	cin >> skip >> x
		>> skip >> y
		>> skip;
	p.setX(x);
	p.setY(y);
}

/*
enter the center point and radius of 3 circles:
(0,0) 3
(1,1) 2
(5,5) 2
perimeter:      A: 18.84        B: 12.56        C: 12.56
area:   A: 28.26        B: 12.56        C: 12.56
enter points until (0,0):
(0,1)
(1,0)
(0,4)
(0,0)
num of points in circle:        A:2     B:2     C:0
*/