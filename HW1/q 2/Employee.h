#pragma once

class Employee {
	int SSN;
	char Name[21];
	float hourly_wage;
	int hours_worked;
	float amount_collected;

public:
	void setSSN(int N) { SSN = N; }
	int getSSN() { return SSN; }

	void set_Name(char* name);
	char* get_Name();

	void set_Wage(float wage) { hourly_wage = wage; }
	float get_Wage() { return hourly_wage; }

	void set_Hours(int hours) { hours_worked = hours; }
	int get_Hours() { return hours_worked; }

	void set_Amount(float amount) { amount_collected = amount; }
	float get_Amount() { return amount_collected; }

	float total_Salary();
};