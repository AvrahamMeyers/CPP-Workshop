#pragma once
#include "Soldier.h"

class Officer : public Soldier {
private:
	int sociometricScore;
public:
	Officer(int, std::string, std::string, int, int);
	void print() override;
	bool Medal() override;
	std::string SoldierType() override;
	int getSocio() override { return sociometricScore; }
	
};

Officer::Officer(int ID, std::string FirstName, std::string LastName, int OperationCount, int sociometricScore)
	: Soldier(ID, FirstName, LastName, OperationCount), sociometricScore(sociometricScore) {} 

void Officer::print() {
	Soldier::print();
	std::cout << "sociometric score " << sociometricScore << std::endl;
}

bool Officer::Medal() {
	if (OperationCount >= 2 && sociometricScore >= 92)
		return true;
	else
		return false;
}

std::string Officer::SoldierType() {
	return "officer";
}

