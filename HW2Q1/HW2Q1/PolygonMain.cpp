/*
PolygonMain.cpp
Uses a polygon class to compare two polygons entered by the user
CPP Workshop
Homework 2 Question 1
Avraham Meyers
Created on 3.14.21 and Modified on 3.16.21
*/

#include <iostream>
#include "Polygon.h"
using namespace std;

void fillPolygon(Polygon& P, int number_of_vertices);
// given a Polygon and the number of vertices that it has
// reads in points from the console, and fills them into the polygon

int main() {
	cout << "enter number of sides:\n";
	int Polygon1_vertices;
	cin >> Polygon1_vertices;
	
	Polygon Polygon1(Polygon1_vertices);//using the constructor to intialize Polygon1

	cout << "enter the point values:\n";

	fillPolygon(Polygon1, Polygon1_vertices);

	cout << "enter number of sides:\n";
	int Polygon2_vertices;
	cin >> Polygon2_vertices;
	
	Polygon Polygon2(Polygon2_vertices);

	cout << "enter the point values:\n";

	fillPolygon(Polygon2, Polygon2_vertices);

	bool equals = Polygon1.polygon_check(Polygon2);

	if (equals == true) {
		cout << "equal. perimeter: "
			<< Polygon1.perimeter() << endl;
	}

	else {
		
		cout << "perimeter: "
			<< Polygon1.perimeter() << endl
			<< "perimeter: "
			<< Polygon2.perimeter() << endl;
	}

	return 0;
}

void fillPolygon(Polygon& P, int number_of_vertices) {
	char skip;
	int x, y;

	for (int i = 0; i < number_of_vertices; i++) {
		cin >> skip >> x >> skip >> y >> skip;
		
		Point Pnt(x, y); //initializing a Point with the x and y values
		P.addPoint(Pnt, i);//putting the point in as the current vertex
	}
}

/*
enter number of sides:
3
in constructor
enter the point values:
(10,10) (13,10) (10,14)
enter number of sides:
3
in constructor
enter the point values:
(13,10) (10,14) (10,10)
in copy-constructor
in destructor
equal. perimeter: 12
in destructor
in destructor
*/