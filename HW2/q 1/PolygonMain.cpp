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

void fillPolygon(Polygon& P, int number_of_vertices);
// given a Polygon and the number of vertices that it has
// reads in points from the console, and fills them into the polygon

int main() {
	std::cout << "enter number of sides:\n";
	int Polygon1_vertices;
	std::cin >> Polygon1_vertices;
	
	Polygon Polygon1(Polygon1_vertices);//using the constructor to intialize Polygon1

	std::cout << "enter the point values:\n";

	fillPolygon(Polygon1, Polygon1_vertices);

	std::cout << "enter number of sides:\n";
	int Polygon2_vertices;
	std::cin >> Polygon2_vertices;
	
	Polygon Polygon2(Polygon2_vertices);

	std::cout << "enter the point values:\n";

	fillPolygon(Polygon2, Polygon2_vertices);

	bool equals = Polygon1.polygon_check(Polygon2);

	if (equals == true) {
		std::cout << "equal. perimeter: "
			<< Polygon1.perimeter() << std::endl;
	}

	else {
		
		std::cout << "perimeter: "
			<< Polygon1.perimeter() << std::endl
			<< "perimeter: "
			<< Polygon2.perimeter() << std::endl;
	}

	return 0;
}

void fillPolygon(Polygon& P, int number_of_vertices) {
	char skip;
	int x, y;

	for (int i = 0; i < number_of_vertices; i++) {
		std::cin >> skip >> x >> skip >> y >> skip;
		
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