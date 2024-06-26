#include "Employee.h"
#include <cstring>

void Employee::set_Name(char* name) {
	strcpy_s(Name, name);
}

char* Employee::get_Name() {
	return Name;
}

float Employee::total_Salary() {
	float salary = 0;
	salary += hours_worked * hourly_wage;

	if (amount_collected <= 1000)
		salary += amount_collected * .1;

	else if (amount_collected <= 2000)
		salary += 100 + ((double(amount_collected) - 1000) * .15);

	else if (amount_collected <= 4000)
		salary += 250 + ((double(amount_collected) - 2000) * .2);

	else if (amount_collected <= 5000)
		salary += 650 + ((double(amount_collected) - 4000) * .3);

	else if (amount_collected > 5000)
		salary += 950 + ((double(amount_collected) - 5000) * .4);

	return salary;
}