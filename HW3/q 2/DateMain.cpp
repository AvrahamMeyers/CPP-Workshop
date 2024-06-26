/*
DateMain.cpp
inputs a date and offers the user options to adjust the date
CPP Workshop
Homework 3 Question 2
Avraham Meyers
Created and Modified on 3.24.21
*/

#include "Date.h"
#include <iostream>

enum{NewDate = 1, PreInc, PostInc, AddDays, Greater, LessThan, Equal};

int main() {
	std::cout << "Enter a date:\n";
	char letter;
	int day, month, year;
	std::cin >> day >> letter
		>> month >> letter
		>> year;
	Date Date1(day, month, year);

	Date1.print();

	int input;
	std::cout << "Enter an action code\n";
	std::cin >> input;

	while (input != -1) {
		switch (input) {
			case NewDate: {
				std::cout << "Enter a date:\n";
				char letter;
				int day, month, year;
				std::cin >> day >> letter
					>> month >> letter
					>> year;
				Date1.setDate(day, month, year);
				Date1.print();
				break;
			}

			case PreInc: {
				(++Date1).print();
				break;
			}

			case PostInc: {
				(Date1++).print();
				break;
			}

			case AddDays: {
				std::cout << "enter #days\n";
				int days;
				std::cin >> days;
				(Date1 += days).print();
				break;
			}

			case Greater: {
				std::cout << "Enter a date:\n";
				char letter;
				int day, month, year;
				std::cin >> day >> letter
					>> month >> letter
					>> year;
				Date Date2(day, month, year);

				std::cout << ">: ";
				Date1 > Date2 ? std::cout << "true\n" : std::cout << "false\n";
				break;
			}

			case LessThan: {
				std::cout << "Enter a date:\n";
				char letter;
				int day, month, year;
				std::cin >> day >> letter
					>> month >> letter
					>> year;
				Date Date2(day, month, year);

				std::cout << "<: ";
				Date1 < Date2 ? std::cout << "true\n" : std::cout << "false\n";
				break;
			}

			case Equal: {
				std::cout << "Enter a date:\n";
				char letter;
				int day, month, year;
				std::cin >> day >> letter
					>> month >> letter
					>> year;
				Date Date2(day, month, year);

				std::cout << "==: ";
				Date1 == Date2 ? std::cout << "true\n" : std::cout << "false\n";
				break;
			}
		}
	std::cout << "Enter an action code\n";
	std::cin >> input;
	}

	return 0;
}
/*
Enter a date:
-5/1/2012
ERROR day
01/01/2012
What do you want to do
1
Enter a date:
5/7/2010
05/07/2010
What do you want to do
2
06/07/2010
What do you want to do
3
06/07/2010
What do you want to do
4
enter # days
7
14/07/2010
What do you want to do
5
Enter a date:
14/7/2010
>: false

What do you want to do
6
Enter a date:
14/7/2010
<: false

What do you want to do
7
Enter a date:
14/7/2010
==: true
What do you want to do
-1
*/