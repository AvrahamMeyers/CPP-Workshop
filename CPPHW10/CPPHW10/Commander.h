#pragma once
#include "Private.h"

class Commander : public Private {
private:
	bool Combat;
public:
	Commander(int, std::string, std::string, int, std::vector<int>, bool);
	void print() override;
	bool Medal() override;
	std::string SoldierType() override;
	bool getCombat() override { return Combat; }
};

Commander::Commander(int ID, std::string FirstName, std::string LastName, int OperationCount, std::vector<int> scores, bool Combat) 
	: Private(ID, FirstName, LastName, OperationCount, scores), Combat(Combat) {} 

void Commander::print() {
	Private::print();
	std::cout << "combat: "
		<< (Combat) ? "yes\n" : "no\n";
}

bool Commander::Medal() {
	if (OperationCount >= 7 && this->AverageScore() >= 90 && Combat == true)
		return true;
	else
		return false;
}

std::string Commander::SoldierType() {
	return "commander";
}