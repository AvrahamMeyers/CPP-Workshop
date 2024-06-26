#include "Polygon.h"
#include <cmath>
#include <iostream>

Polygon::Polygon(int number_of_vertices) {
	vertexcount = number_of_vertices;
	vertices = new Point[vertexcount];//dynamically allocating a new array with the size of the number of vertices
	std::cout << "in constructor\n";
};

Polygon::Polygon(const Polygon& other) {
	this->vertexcount = other.vertexcount;

	this->vertices = new Point[this->vertexcount]; 

	for (int i = 0; i < other.vertexcount; i++) {
		this->vertices[i] = other.vertices[i]; //copying the values for the vertices from 
	}										// the other polygon to this polygon

	std::cout << "in copy-constructor\n";
}

Polygon::~Polygon() {
	delete[] this->vertices;
	std::cout << "in destructor\n";
}

void Polygon::addPoint(Point vertex, int index) {
	this->vertices[index] = vertex;
}

float Polygon::perimeter() {
	Point previousvertex = vertices[0];
	float perimeter = 0;
	for (int i = 1; i < vertexcount; i++) { //looping through the array of vertices and adding the distance between each point
		perimeter += vertices[i].distance(previousvertex.get_x(), previousvertex.get_y());
		previousvertex = vertices[i];
	}

	perimeter += vertices[vertexcount - 1].distance(vertices[0].get_x(), vertices[0].get_y()); 
	//calculating the distance between the last point and the first point
	return perimeter;
}

bool Polygon::polygon_check(Polygon received) {
	bool PointsCheck(Point P, Point Q);
	//checks whether two Points are the same
	
	if (this->vertexcount != received.vertexcount) //if the number of vertices is not the same, return false
		return false;

	for ( int receivedindex = 0; receivedindex < received.vertexcount; receivedindex++) { //loopong through both arrays
		int thisindex;														// and checking whether any Points in the this array
		for (thisindex = 0; thisindex < this->vertexcount; thisindex++) {// are the same as the current Point in the received array
			if (PointsCheck(received.vertices[receivedindex], vertices[thisindex]))
				break; //if the Points are the same, leave the for loop early
		}

		if (thisindex == this->vertexcount)// if the index for the inner for loop reached the end of the loop
			return false; // then none of the Points in the this array matched the current Point in the received array
	} // so the two arrays are not the same

	return true;
}

bool PointsCheck(Point P, Point Q) {
	if (P.get_x() == Q.get_x()
		&& P.get_y() == Q.get_y())
		return true;
	else
		return false;
}