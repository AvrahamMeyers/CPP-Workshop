#pragma once
#include <string>
#include <iostream>

class Account {
	int accountNumber, code;
	float balance;
	std::string mail;
	static float sumWithdraw;
	static float sumDeposit;

public:

	Account() : accountNumber(0), code(0), balance(0), mail(std::string()) {};
	Account(int accountNumber, int code, float balance, std::string mail) : 
		accountNumber(accountNumber), code(code), balance(balance), mail(mail) {};

	int getAccountNumber() { return this->accountNumber; }
	int getCode() { return this->code; }
	float getBalance() { return this->balance; }
	std::string getMail() { return this->mail; }

	void set_balance(float balance) { this->balance = balance; }
	void set_mail(std::string mail) { this->mail = mail; }

	friend std::istream& operator>>(std::istream& in, Account& A);

	void withdraw(float NIS);

	void deposit(float NIS); 

	static float getSumWithdraw() { return sumWithdraw; }
	static float getSumDeposit() { return sumDeposit; }

};