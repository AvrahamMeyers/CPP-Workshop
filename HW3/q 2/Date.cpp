#include "Date.h"
#include <iostream>

Date Date::operator++() {//pre auto
	if (this->day == 30) {//if the number of days is 30 then 
						// the month will have to be incremented
		if (this->month == 12) {//if the number of months is 12
			this->month = 1;//the number of years must be incremented
			this->year++;
		}
		else 
			this->month++;

		this->day = 1;//and the day is 1
	}
	else
		this->day++;

	return *this;
}

Date Date::operator++(int) {//post auto
	Date prev = *this;

	if (this->day == 30) {

		if (this->month == 12) {
			this->month = 1;
			this->year++;
		}
		else
			this->month++;

		this->day = 1;
	}

	else
		this->day++;

	return prev;
}

Date Date::operator+=(int days) {
	this->day += days;

	if (this->day > 30) {
		this->day = this->day - 30;

		if (this->month == 12) {
			this->month = 1;
			this->year++;
		}
		else
			this->month++;
	}

	return *this;
}

bool Date::operator<(const Date& D) const {
	if (this->year > D.year)
		return false;
	if (this->year < D.year)
		return true;

	if (this->month > D.month)
		return false;
	if (this->month < D.month)
		return true;

	if (this->day >= D.day)
		return false;

	return true;
}

bool Date::operator>(const Date & D) const {
	if (this->year < D.year)
		return false;
	if (this->year > D.year)
		return true;

	if (this->month < D.month)
		return false;
	if (this->month > D.month)
		return true;

	if (this->day <= D.day)
		return false;

	return true;

}

bool Date::operator==(const Date& D) const {
	if (this->day != D.day)
		return false;
	if (this->month != D.month)
		return false;
	if (this->year != D.year)
		return false;

	return true;
}

void Date::setDate(int day, int month, int year) {
	if (day <= 30 && day >= 1) {
		this->day = day;
	}

	if (month <= 12 && month >= 1) {
		this->month = month;
	}

	if (year < 2099 && year > 1920) {
		this->year = year;
	}
}

void Date::print() {
	/*if (day < 10)
		cout << '0';*/
	std::cout << day << '/';
	/*if (month < 10)
		cout << '0';*/
	std::cout << month << '/';
	std::cout << year << endl;
}
