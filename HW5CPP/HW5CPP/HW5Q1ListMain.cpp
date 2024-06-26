/*
ListMain.cpp
implements a linked list
CPP Workshop
Homework 5 Question 1
Avraham Meyers
Created on 4.25.21 and Modified on 4.26.21
*/

#include <iostream>
#include "List.h"

int main() {

	List lst;
	int choice, val;
	std::cout << "enter the list values\n";
	std::cin >> lst;
	std::cout << "choose 0-2\n";
	std::cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case 1: std::cout << "enter a value to insert\n";
			std::cin >> val;
			lst.insert(val);
			break;
		case 2: std::cout << "enter a value to remove\n";
			std::cin >> val;
			try {
				lst.remove(val);
			}
			catch (const char* msg)
			{
				std::cout << msg << std::endl;
			}
			break;
		default: std::cout << "ERROR\n";
		}
		std::cout << lst << std::endl;
		std::cout << "choose 0-2\n";
		std::cin >> choice;
	}
	return 0;
}
/*
enter the list values
3 2 1 1
choose 0-2
2
enter a value to remove
2
3 1
choose 0-2
1
enter a value to insert
4
4 3 1
choose 0-2
1
enter a value to insert
6
6 4 3 1
choose 0-2
1
enter a value to insert
2
6 4 3 2 1
choose 0-2
2
enter a value to remove
3
6 4 2 1
choose 0-2
0*/
