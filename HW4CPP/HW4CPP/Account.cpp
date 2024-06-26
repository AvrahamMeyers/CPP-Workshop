#include "Account.h"

std::istream& operator>>(std::istream& in, Account& A) {
	in >> A.accountNumber >> A.code >> A.mail;
	A.balance = 0;
	return in;
}

void Account::withdraw(float NIS) {

	if (this->balance - NIS < -6000)
		throw "ERROR: cannot have less than -6000 NIS\n";
	if (NIS > 2500)
		throw "ERROR: cannot withdraw more than 2500 NIS\n";
	
	this->balance -= NIS;

	sumWithdraw += NIS;
}

void Account::deposit(float NIS) {
	
	if (NIS > 10000)
		throw "ERROR: cannot deposit more than 10000 NIS\n";

	this->balance += NIS;

	sumDeposit += NIS;
}