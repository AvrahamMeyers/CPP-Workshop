#pragma once
#include <string>
#include <iostream>
#include <vector>

class Soldier {
protected:
	int ID;
	std::string FirstName;
	std::string LastName;
	int OperationCount;

public:
	int getID() { return ID; }
	std::string getFirstName() { return FirstName; }
	std::string getLastName() { return LastName; }
	virtual int getOperationCount() { return OperationCount; }
	virtual std::vector<int>* getScores() { throw "ERROR: this function is just for private soldier\n"; }
	virtual bool getCombat() { throw "ERROR: this function is just for commander soldier\n"; }
	virtual int getSocio() { throw "ERROR: this function is just for officer soldier\n"; }	
	
	
	Soldier(int, std::string, std::string, int);
	virtual ~Soldier();
	virtual bool Medal() = 0;
	virtual void print();
	virtual std::string SoldierType() = 0;
};

Soldier::Soldier(int ID, std::string FirstName, std::string LastName, int OperationCount)
	: ID(ID), FirstName(FirstName), LastName(LastName), OperationCount(OperationCount) {}

//Soldier::Soldier() : ID(0), FirstName(""), LastName(""), OperationCount(0) {}

void Soldier::print() {
	std::cout << SoldierType() << std::endl;
	std::cout << "ID: " << ID << std::endl
		<< "first name: " << FirstName << std::endl
		<< "last name: " << LastName << std::endl
		<< "num operations: " << OperationCount << std::endl;
}

Soldier::~Soldier() {
	//delete this->FirstName;
	//delete this->LastName;
}