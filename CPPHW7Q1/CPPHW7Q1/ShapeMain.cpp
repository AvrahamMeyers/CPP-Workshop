/*
ShapeMain.cpp
creates triangles, circles, and rectangles made by the user
CPP Workshop
Homework 7 Question 1
Avraham Meyers
Created and Modified on 11.5.21
*/

#include <iostream>
#include "Shape.h"

int main() {
	std::cout << "How many shapes you would like to define?\n";
	int NumofShapes;
	std::cin >> NumofShapes;
	Shape** collection = new Shape*[NumofShapes];

	for (int i = 0; i < NumofShapes; i++) {
		std::cout << "Which shape will you choose? Circle-1, Triangular-3, Rectangle-4\n";
		int option;
		std::cin >> option;

		switch (option) {
			case 1: {
				int radius;
				std::cout << "Enter radius:\n";
				std::cin >> radius;
				if (radius < 0) {
					std::cout << "invalid input\n";
					break;
				}
				collection[i] = new Circle(radius);
				break;
			}
			case 3: {
				collection[i] = new Triangle();
				break;
			}
			case 4: {
				collection[i] = new Rectangle();
				break;
			}
			default: {
				std::cout << "invalid input\n";
				i--;
				break;
			}
		}
	}

	for (int i = 0; i < NumofShapes; i++) {
		std::cout << *(collection[i]) << ' '
			<< "area is: " << collection[i]->area() << std::endl;
		if (collection[i]->isSpecial()) {
			collection[i]->printSpecial();
		}
	}

	return 0;
}
/*How many shapes you would like to define?
3
Which shape will you choose? Circle-1, Triangular-3, Rectangle-4
3
Enter values of 3 points:
(0,0) (1,1) (1,0)
Which shape will you choose? Circle-1, Triangular-3, Rectangle-4
1
Enter radius:
4
Enter values of 1 points:
(0,0)
Which shape will you choose? Circle-1, Triangular-3, Rectangle-4
4
Enter values of 4 points:
(0,0) (1,0) (1,1) (0,1)
points: (0,0) (1,1) (1,0)  area is: 0.5
points: (0,0)  area is: 50.24
A canonical circle with a radius 4
points: (0,0) (1,0) (1,1) (0,1)  area is: 1
Square with a side length 1*/
