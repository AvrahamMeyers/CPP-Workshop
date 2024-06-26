#pragma once
#include "Employee.h"

class FullTime : public Employee {
	float annualsalary;

public:
	FullTime(std::string name, int ID, int seniority, float annualsalary) 
		: Employee(name, ID, seniority), annualsalary(annualsalary) {}

	FullTime() : Employee("", 0, 0), annualsalary(0) {}

	float getAnnual() { return annualsalary; }
	void setAnnual(float annualsalary) { this->annualsalary = annualsalary; }

	float SalaryAfterBonus() {
		this->pay = this->annualsalary / 12.0;
		return Employee::SalaryAfterBonus();
	}

	float salary() {
		return this->annualsalary / 12.0;
	}

	friend std::istream& operator>>(std::istream& in, FullTime& F) {
		in >> (Employee&)F >> F.annualsalary;
		
		if (F.ID < 0 || F.seniority < 0 || F.pay < 0)
			throw "ERROR\n";

		if (F.annualsalary < 0)
			throw "ERROR\n";

		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, FullTime& F) {
		out << (Employee&)F
			<< "Salary per Month:\t"
			<< F.annualsalary / 12.0 << std::endl;
		return out;
	}






};