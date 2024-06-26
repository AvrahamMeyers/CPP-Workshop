#include <iostream>
#include "Rational.h"

void Rational::print() {
	std::cout << numerator << '/' << denominator;
}

bool Rational::equal(Rational r) {
	Rational localreduced = reduction(); //reducing the local Rational

	Rational foreignreduced = r.reduction();

	if (localreduced.GetNum() == foreignreduced.GetNum() //if the numerator and the denominator of both
		&& localreduced.GetDenom() == foreignreduced.GetDenom()) // reduced rationals are equal
		return true; // return true
	else
		return false;
}

Rational Rational::Add(Rational r) {
	Rational sum;

	sum.SetNum((numerator * r.GetDenom()) + (r.GetNum() * denominator) ); //setting sum to the sum of the two rationals
	sum.SetDenom(denominator * r.GetDenom());
	// reducing sum
	sum = sum.reduction();

	return sum;
}

Rational Rational::reduction() {
	Rational reduced;

	reduced.SetNum(numerator);
	reduced.SetDenom(denominator);

	int a, b;

	if (reduced.GetNum() == reduced.GetDenom()) { //if the numerator and denominator are equal
		reduced.SetNum(1);						// the reduced rational is simply 1/1	
		reduced.SetDenom(1);
		return reduced;
	}
	
	else if (reduced.GetNum() > reduced.GetDenom()) {
		a = reduced.GetNum();
		b = reduced.GetDenom();
	}
	else if (reduced.GetNum() < reduced.GetDenom()) {
		a = reduced.GetDenom();
		b = reduced.GetNum();
	}

	int temp;

	while (b != 0) { // using Euclids algorithm to find the GCD of the rational
        temp = b;
        b = a % b;
        a = temp;
    }

    reduced.SetNum(reduced.GetNum() / a); //dividing the numerator and denominator by the GCD
    reduced.SetDenom(reduced.GetDenom() / a);

    return reduced;
	}
