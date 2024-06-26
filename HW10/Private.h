#pragma once
#include "Soldier.h"
#include <vector>

class Private : public Soldier {
private:
	std::vector<int>* scores;

public:
	virtual void print() override;
	virtual bool Medal();
	Private(int, std::string, std::string, int, std::vector<int>);
	~Private();
	
	virtual std::string SoldierType() override;
	std::vector<int>* getScores() override { return scores; }

protected:
	float AverageScore();
};

void Private::print() {
	Soldier::print();

	std::cout << "grades: ";

	for (int i = 0; i < OperationCount; i++)
		std::cout << (*scores)[i] << ' ';
	std::cout << std::endl;
}

Private::~Private() {
	delete[] scores;
}

bool Private::Medal() {
	if (OperationCount >= 10 && this->AverageScore() >= 95.0)
		return true;
	else
		return false;
}

float Private::AverageScore() {
	int sum = 0;
	for (int i = 0; i < OperationCount; i++)
		sum += (*scores)[i];
	return sum / OperationCount;
}

std::string Private::SoldierType() {
	return "private";
}

Private::Private(int ID, std::string FirstName, std::string LastName, int OperationCount, std::vector<int> scores)
	: Soldier(ID, FirstName, LastName, OperationCount) {
	this->scores = new std::vector<int>(scores);
}