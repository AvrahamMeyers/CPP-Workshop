/*
EmployeeMain.cpp
Accepts data for employees of an organizaion, and prints the data
for the employee who collected the least amount of money, and the employee
who earned the highest salary
CPP Workshop
Homework 1 Question 2
Avraham Meyers
Created on 3.9.21 and Modified on 3.10.21
*/
#include "Employee.h"
#include <iostream>
#include <cstring>


void fillEmployee(Employee& E, int entrySSN);
// given an Employee and the SSN that was entered for the employee,
// reads in the rest of the information for the employee from the console
void copyEmployee(Employee& source, Employee& destination);
//given two employees, copys the values from the source Employee
// to the destination Employee

int main() {
	std::cout << "enter details, to end enter 0:\n";
	Employee entry, highest_Salary, least_Collected; //declaring three Employees
	// to hold the information for the employee who collected the least, earned the highest
	// salary, and the entry from the user
	
	int entrySSN;
	std::cin >> entrySSN;

	fillEmployee(entry, entrySSN);
	copyEmployee(entry, highest_Salary);
	copyEmployee(entry, least_Collected);

	if (entry.get_Hours() < 1 || //checking if the first entry had any illegal inputs
			entry.get_Wage() < 1 ||
			entry.get_Amount() < 1) {

			std::cout << "ERROR\n";
		}

	std::cin >> entrySSN; //reading in the next employee SSN from the console
	while (entrySSN != 0) {
		
		fillEmployee(entry, entrySSN);
		
		if (entry.get_Hours() < 1 ||
			entry.get_Wage() < 1 ||
			entry.get_Amount() < 1) {

			std::cout << "ERROR\n";
			std::cin >> entrySSN;
			continue;
		}

		if (entry.get_Amount() < least_Collected.get_Amount())
			copyEmployee(entry, least_Collected);

		if (entry.total_Salary() > highest_Salary.total_Salary())
			copyEmployee(entry, highest_Salary);

		std::cin >> entrySSN;
	} 

	std::cout << "minimum sum: " << least_Collected.get_Amount() << ' ' 
		<< least_Collected.get_Name() << ' '
		<< least_Collected.getSSN() << std::endl;

	std::cout << "highest salary: " << highest_Salary.total_Salary() << ' '
		<< highest_Salary.get_Name() << ' '
		<< highest_Salary.getSSN();

	return 0;

	
}

void fillEmployee(Employee& E, int entrySSN) {
	int hours_worked;
	char name[21];
	float hourly_wage, amount_collected;
	std::cin >> name;
	std::cin >> hourly_wage >> hours_worked >> amount_collected;

	

	E.setSSN(entrySSN);
	E.set_Name(name);
	E.set_Wage(hourly_wage);
	E.set_Hours(hours_worked);
	E.set_Amount(amount_collected);
}

void copyEmployee(Employee& source, Employee& destination) {
	destination.setSSN(source.getSSN());
	destination.set_Name(source.get_Name());
	destination.set_Wage(source.get_Wage());
	destination.set_Hours(source.get_Hours());
	destination.set_Amount(source.get_Amount());
}

/*
enter details, to end enter 0:
123456789 moshe 50 40 2000
987654321 rivka 120 55 3450
975312468 sara 35 100 5632
0
minimum sum: 2000 moshe 123456789
highest salary: 7140 rivka 987654321
*/