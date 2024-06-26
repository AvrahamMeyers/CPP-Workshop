/*
ATMMain.cpp
Runs a standard ATM with 10 accounts
CPP Workshop
Homework 4
Avraham Meyers
Created on 4.10.21 and Modified on 4.20.21
*/

#include <iostream>
#include "Clock.h"
#include "Account.h"


float Account::sumDeposit = 0;
float Account::sumWithdraw = 0;

enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};
action menu()
{
	std::cout << "enter 1 to get account balance" << std::endl;
	std::cout << "enter 2 to deposit money" << std::endl;
	std::cout << "enter 3 to withdraw money" << std::endl;
	std::cout << "enter 4 to see the sum of all withdraws" << std::endl;
	std::cout << "enter 5 to see the sum of all Deposits" << std::endl;
	std::cout << "enter 0 to stop" << std::endl;
	int x;
	std::cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size)
{
	int number, code;
	std::cout << "please enter account number: ";
	std::cin >> number;
	if (number < 1 || number > 10)
		throw "ERROR: no such account number!\n";
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
	std::cout << "please enter the code: ";
	std::cin >> code;
	if (bank[i].getCode() == code)
		return i;
	else
		throw "ERROR: wrong code!\n";
}
void printTransaction(Account a, action ac, Clock& c)
{
	std::cout << c << "\t";
	;
	switch (ac)
	{
	case balance: std::cout << "account #: " << a.getAccountNumber() << "\t";
		std::cout << "balance: " << a.getBalance() << std::endl;
		break;
	case deposit:
	case withdraw: std::cout << "account #: " << a.getAccountNumber() << "\t";
		std::cout << "new balance: " << a.getBalance() << std::endl;
		break;
	case sumDeposit:
		std::cout << "sum of all deposits: " << Account::getSumDeposit() << std::endl;
		break;
	case sumWithdraw:
		std::cout << "sum of all withdraws: " << Account::getSumWithdraw() << std::endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], balance, c);
}
void cashDeposit(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	float amount;
	std::cout << "enter the amount of the check: ";
	std::cin >> amount;
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], deposit, c);
}
void cashWithdraw(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	float amount;
	std::cout << "enter the amount of money to withdraw: ";
	std::cin >> amount;
	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], withdraw, c);
}

int main()
{
	Clock c(8);
	Account bank[10];
	std::cout << "enter account number and code for 10 accounts:\n";
	for (int i = 0; i < 10; i++)
	{
		try {
			std::cin >> bank[i];
			for (int j = 0; j < i; j++) 
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
					throw "ERROR: account number must be unique!\n";

				if (bank[i].getCode() < 1000 || bank[i].getCode() > 9999)
					throw "ERROR: code must be of 4 digits!\n";

				int length = bank[i].getMail().size();
				int dotcom = bank[i].getMail().find(".com");
				int dot_co_dot_il = bank[i].getMail().find(".co.il");
				int at_location = bank[i].getMail().find('@');

				if (dot_co_dot_il == -1) {
					if (dotcom == -1)
						throw "ERROR: email must end at .com!\n";
					if (length - dotcom > 4)//using the difference between the length of the email
						throw "ERROR: email must end at .com!\n";// and the location of the .com
					if (at_location > dotcom)					//to determine if the .com is the last segment in the email	
						throw "ERROR: email must end at .com!\n";

				}
				else {
					if (length - dot_co_dot_il > 6)
						throw "ERROR: email must end at .co.il!\n";
					if (at_location > dot_co_dot_il)
						throw "ERROR: email must end at .co.il!\n";
				}

				if (at_location == -1) 
					throw "ERROR: email must contain @!\n";
					
		}
		catch (const char* msg)
		{
			std::cout << c << '\t' << msg;
			i--;
		}
	}
	action ac = menu();
	while (ac)
	{
		switch (ac)
		{
		case balance: try { getBalance(bank, 10, c); }
					catch (const char* ErrorMessage) {
						std::cout << c << '\t' << ErrorMessage;
					}
			break;
		case withdraw: try { cashWithdraw(bank, 10, c); }
					 catch (const char* ErrorMessage) {
						 std::cout << c << '\t' << ErrorMessage;
					 }
					 break;
		case deposit: try { cashDeposit(bank, 10, c); }
					catch (const char* ErrorMessage) {
						std::cout << c << '\t' << ErrorMessage;
					}
					break;
		case sumDeposit:c += 60;
			printTransaction(bank[0], sumDeposit, c);
			break;
		case sumWithdraw:c += 60;
			printTransaction(bank[0], sumWithdraw, c);

		}
		ac = menu();
	}
	return 0;
}

/*enter account number and code for 10 accounts:
1 1111 aaa@gmail.com
2 2222 aaa@gmail.com
3 3333 bbb@gmail.com
4 4444 ccc@gmail.com
5 5555 ddd@gmail.com
6 6666 eee@gmail.comA
7 7777 fff@gmail.com
8 8888 ggg@gmail.com
9 9999 hhh@gmail.com
10 1010 iii@gmail.com
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
2
please enter account number: 4
please enter the code: 4444
enter the amount of the check: 4000
08:00:30
        account #: 4    new balance: 4000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
2
please enter account number: 5
please enter the code: 5555
enter the amount of the check: 5000
08:01:00        account #: 5    new balance: 5000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
3
please enter account number: 4
please enter the code: 4444
enter the amount of money to withdraw: 1000
08:01:50
        account #: 4    new balance: 3000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
3
please enter account number: 4
please enter the code: 4444
enter the amount of money to withdraw: 500
08:02:40
        account #: 4    new balance: 2500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
1
please enter account number: 4
please enter the code: 4444
08:03:00        account #: 4    balance: 2500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
1
please enter account number: 5
please enter the code: 5555
08:03:20
        account #: 5    balance: 5000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
4
08:04:20
        sum of all deposits: 9000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
5
08:05:20
        sum of all withdraws: 1500
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all withdraws
enter 5 to see the sum of all Deposits
enter 0 to stop
0*/