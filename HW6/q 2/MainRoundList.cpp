/*
MainRoundList.cpp
Performs basic methods on a circular linked list
CPP Workshop
Homework 6 Question 2
Avraham Meyers
Created and Modified on 5.5.21
*/

#include "RoundList.h"
#include <iostream>


enum CHOICES {
	EXIT, ADD, ADD_TO_END, REMOVE_FIRST, SEARCH, CLEAR, EMPTY
};
int main() {

	RoundList ls1;
	int choice;
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	while (choice != EXIT)
	{
		int num;
		switch (choice) {
		case ADD: 	std::cout << "Enter 5 numbers: ";
			for (int i = 0; i < 5; i++)
			{
				std::cin >> num;
				ls1.add(num);
			}
			break;

		case ADD_TO_END:std::cout << "Enter 5 numbers: ";
			for (int i = 0; i < 5; i++)
			{
				std::cin >> num;
				ls1.AddtoEnd(num);
			}
			break;

		case REMOVE_FIRST: try { ls1.removeFirst(); }
						 catch (const char* Msg) {
							 std::cout << Msg << std::endl;
						 }
			break;

		case SEARCH: std::cout << "Enter a number: ";
			std::cin >> num;
			std::cout << ls1.search(num) << std::endl;
			break;

		case CLEAR: ls1.clear();
			break;

		case EMPTY: if (ls1.isEmpty())
			std::cout << "Empty" << std::endl;
				  else
			std::cout << "Not empty" << std::endl;
			break;

		default: std::cout << "ERROR!" << std::endl;
		}
		std::cout << "Enter your choice: ";
		std::cin >> choice;
	}
	return 0;
}

/*Enter your choice: 3
the List is empty, no Elements to remove
Enter your choice: 1
Enter 5 numbers: 1 2 3 4 5
Enter your choice: 2
Enter 5 numbers: 6 7 8 9 10
Enter your choice: 3
Enter your choice: 4
Enter a number: 6
7
Enter your choice: 5
Enter your choice: 6
Empty
Enter your choice: 0
*/
