#include "Commander.h"
#include "Officer.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


enum option {
	stop,	//	End program
	addNewSoldier,	//	Add new soldier
	medalList,	//	Print all soldiers that are entitled to a medal
	mostSociometric,	//	Most sociometric score 
	countMedalPrivate,	//	Number of private soldiers getting a medal
	noCombatCommander,	//	Names of officers not combat
	overSoldier,	//	A message for soldier participating in more than 15 operations
	removeOfficer,	//	Removing officers that did'nt participate in any operation
};

void add(std::vector<Soldier*>& V);
void Medal(std::vector<Soldier*> V);
Soldier* mostSociometricScore(std::vector<Soldier*> V);

int main() {
	std::vector<Soldier*> V;

	int op;
	std::cout << "enter 0-7\n";
	std::cin >> op;
	while (op != stop)
	{
		switch (op)
		{
		case addNewSoldier:add(V);
			break;
		case medalList:Medal(V);
			break;
		case mostSociometric: {
			Soldier* s = mostSociometricScore(V);
			std::cout << "Officer soldier with most sociometric score: ";
			std::cout << s->getFirstName() << ' ' << s->getLastName() << std::endl;
			break; }
		case countMedalPrivate:
			std::cout << "# private soldier for medal: ";
			std::cout << std::count_if(V.begin(), V.end(), 
				[](Soldier* S) {if (S->SoldierType() == "private") return S->Medal(); });
			std::cout << std::endl;
			break;
		case noCombatCommander:
			std::cout << "list of no combat commander soldier :";
				std::for_each(V.begin(), V.end(),
					[](Soldier* S) {if (S->SoldierType() == "commander" && S->getCombat() == false) 
					std::cout << S->getFirstName() << ' ' << S->getLastName() << ' '; });
			std::cout << std::endl;
			break;
		case overSoldier:
			if (std::any_of(V.begin(), V.end(), [](Soldier* S) {return S->getOperationCount() >= 15; }))
				std::cout << "there is a soldier that takes more than 15 operations\n";
			else
				std::cout << "no soldier takes more than 15 operations\n";
			break;
		case removeOfficer:
			std::remove_if(V.begin(), V.end(), 
				[](Soldier* S) {if (S->SoldierType() == "officer") return S->getOperationCount() == 0; });
			std::for_each(V.begin(), V.end(), [](Soldier* S) {S->print(); });
			break;
		};
		std::cout << "enter 0-7\n";
		std::cin >> op;
	}
	return 0;
}

void add(std::vector<Soldier*>& V) {
	std::cout << "enter 1 to add a private soldier\n";
	std::cout << "enter 2 to add a commander soldier\n";
	std::cout << "enter 3 to add a officer soldier\n";
	int entry;
	std::cin >> entry;
	std::cout << "enter id, first name, last name and number Of operations\n";
	int ID, NumofOps;
	std::string FirstName, LastName;
	std::cin >> ID >> FirstName >> LastName >> NumofOps;
	switch (entry) {
		case 1: {
			std::vector<int> scores;
			if (NumofOps > 0) {
				std::cout << "enter " << NumofOps << " grades\n";
				int score;
				for (int i = 0; i < NumofOps; i++) {
					std::cin >> score;
					scores.push_back(score);
				}
			}
			V.push_back(new Private(ID, FirstName, LastName, NumofOps, scores));
			break;
		}
		case 2: {
			std::vector<int> scores;
			if (NumofOps > 0) {
				std::cout << "enter " << NumofOps << " grades\n";
				int score;
				for (int i = 0; i < NumofOps; i++) {
					std::cin >> score;
					scores.push_back(score);
				}
			}
			std::cout << "enter 1 if the soldier is combat and 0 if not\n";
			bool Combat;
			std::cin >> Combat;
			V.push_back(new Commander(ID, FirstName, LastName, NumofOps, scores, Combat));
			break;
		}
		case 3: {
			std::cout << "enter number of sociometric score\n";
			int socio;
			std::cin >> socio;
			V.push_back(new Officer(ID, FirstName, LastName, NumofOps, socio));
			break;
		}
	}
}

void Medal(std::vector<Soldier*> V) {
	std::for_each(V.begin(), V.end(), [](Soldier* S) {if(S->Medal()) S->print(); });
}

Soldier* mostSociometricScore(std::vector<Soldier*> V) {
	Soldier* s = nullptr;
	int highestSocio = 0;
	bool isOfficer = true;

	std::vector<Soldier*>::iterator it = V.begin();
	for (; it != V.end(); ++it) {
		try { (*it)->getSocio(); }
		catch (const char* Msg) {
			isOfficer = false;
		}
		if (isOfficer) {
			if ((*it)->getSocio() > highestSocio) {
				highestSocio = (*it)->getSocio();
				s = (*it);
			}
		}
		isOfficer = true;
	}
	return s;
}

