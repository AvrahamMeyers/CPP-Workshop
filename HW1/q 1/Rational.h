#pragma once

class Rational {
	int numerator;
	int denominator;

public:
	void SetNum(int n) { numerator = n; }
	void SetDenom(int d) { if (d != 0) denominator = d; else denominator = 1; }
	int GetNum() { return numerator; }
	int GetDenom() { return denominator; }

	void print();
	Rational Add(Rational r);
	bool equal(Rational r);

private:
	Rational reduction();
};