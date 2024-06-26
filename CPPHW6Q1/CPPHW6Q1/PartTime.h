#pragma once
#include "Employee.h"

class PartTime : public Employee {
	float workinghours;
	float hourlyrate;

public:
	PartTime(std::string name, int ID, int seniority, float pay, float workinghours, float hourlyrate)
		: Employee(name, ID, seniority), workinghours(workinghours), hourlyrate(hourlyrate) {}

	PartTime() : Employee( "", 0, 0), workinghours(0), hourlyrate(0) {}
	
	float getWorkinghours() { return this->workinghours; }
	void setWorkinghours(float workinghours) { this->workinghours = workinghours; }
	float getHourlyrate() { return this->hourlyrate; }
	void setHourlyrate(float hourlyrate) { this->hourlyrate = hourlyrate; }

	float salary() {
		return workinghours * hourlyrate;
	}

	float SalaryAfterBonus() {
		this->pay = workinghours * hourlyrate;
		return Employee::SalaryAfterBonus();
	}

	friend std::istream& operator>>(std::istream& in, PartTime& P) {
		in >> (Employee&)P >> P.workinghours >> P.hourlyrate;

		if (P.ID < 0 || P.seniority < 0 || P.pay < 0)
			throw "ERROR\n";
		
		if (P.workinghours < 0 || P.hourlyrate < 0)
			throw "ERROR\n";

		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, PartTime& P) {
		out << (Employee&)P
			<< "Hours:\t" << P.workinghours 
			<< std::endl
			<< "Salary Per Month:\t" << (P.workinghours * P.hourlyrate)
			<< std::endl;
		return out;
	}
};