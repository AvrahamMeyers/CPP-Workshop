/*
RationalMain.cpp
Adds two rational numbers together and checks if they are equal
CPP Workshop
Avraham Meyers
Created and Modified on 3.8.21
*/

#include"Rational.h"
#include <iostream>
//using namespace std;

int main()
{
	int numerator, denominator;
	char tav;
	std::cout << "enter two rational numbers:" << std::endl;
	std::cin >> numerator >> tav >> denominator;
	Rational r1;
	r1.SetNum(numerator);
	r1.SetDenom(denominator);
	std::cin >> numerator >> tav >> denominator;
	Rational r2;
	r2.SetNum(numerator);
	r2.SetDenom(denominator);
	Rational ans = r1.Add(r2);
	r1.print();
	std::cout << " + ";
	r2.print();
	std::cout << " = ";
	ans.print();
	std::cout << std::endl;
	if (r1.equal(r2))
		std::cout << "The two numbers are equal" << std::endl;
	else
	{
		std::cout << "The two numbers are different" << std::endl;
		r1.print();
		std::cout << ' ';
		r2.print();
		std::cout << std::endl;
	}
	return 0;
}

/*
enter two rational numbers:
1/2 3/6
1/2+ 3/6= 1/1
The two numbers are equal

enter two rational numbers:
1/2 3/4
1/2 + 3/4= 5/4
The two numbers are different
1/2 3/4

*/
