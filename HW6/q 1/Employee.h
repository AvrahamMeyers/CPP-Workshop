#pragma once
#include <iostream>
#include <string>

class Employee {

protected:
	std::string name;
	int ID;
	int seniority;
	float pay;

public:
	Employee(std::string name, int ID, int seniority) : name(name), ID(ID), seniority(seniority), pay(0) {}

	std::string getName() { return name; }
	int getID() { return ID; }
	int getSeniority() { return seniority; }
	float getPay() { return pay; }
	void setSeniority(int seniority) { this->seniority = seniority; }
	void setPay(float pay) { this->pay = pay; }
	
	float SalaryAfterBonus() {
		if (seniority < 6) {
			pay += 500;
		}
		else
			pay *= 1.25;

		return pay;
	}

	friend std::istream& operator>>(std::istream& in, Employee& E) {
		std::cout << "Enter employee details:\n";

		in >> E.name >> E.ID >> E.seniority;
		E.pay = 0;

		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, Employee& E) {
		out << "Employee:\t" << E.name << std::endl
			<< "Employee ID:\t" << E.ID << std::endl
			<< "Years seniority:\t" << E.seniority << std::endl;
		return out;		
	}


};