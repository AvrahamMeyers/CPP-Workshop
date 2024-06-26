#pragma once
#include <iostream>
using namespace std;

class Date {
	int day;
	int month;
	int year;

public:
	Date(int day = 1, int month = 1, int year = 1920)
	{
		if (day > 30 || day < 1) {
			cout << "Error day\n";
			this->day = 1;
		}
		else { this->day = day; }

		if (month > 12 || month < 1) {
			cout << "Error month\n";
			this->month = 1;
		}
		else { this->month = month; }

		if (year > 2099 || year < 1920) {
			cout << "Error year\n";
			this->year = 1920;
		}
		else { this->year = year; }
	}

	Date(const Date& D) : day(D.day), month(D.month), year(D.year) {};

	Date operator++();//pre auto
	Date operator++(int);//post auto
	Date operator+=(int days);

	bool operator>(const Date& D) const;
	bool operator<(const Date& D) const;
	bool operator==(const Date& D) const;

	void setDate(int day, int month, int year);
	void print();

};