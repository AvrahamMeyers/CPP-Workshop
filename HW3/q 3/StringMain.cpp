/*
StringMain.cpp
Uses a string class to check how two strings relate to each other, 
and inserts the first string into the second, and replaces one of the characters in the string
CPP Workshop
Homework 3 Question 3
Avraham Meyers
Created and Modified on 4.7.21
*/

#include <iostream>
#include <cstring>
#include "String.h"

int main() {
	char* firstword = new char[80], * secondword = new char[80];

	std::cin >> firstword >> secondword;
	String word1(firstword), word2(secondword);

	int num;
	std::cin >> num;

	if (word1 < word2)//checking if word1 is less than or greater than word2
		std::cout << "a<b\n";
	else if (word1 > word2)
		std::cout << "a>b\n";
	else
		std::cout << "a=b\n";//if it is neither less than or greater than, then they must be equal

	String combo = word2.insert(num, firstword);
	combo.Print();

	int i;
	char c;
	std::cin >> c >> i;

	if (i >= combo.getLen()) {//if the index entered is not within the bounds of the string 
		std::cout << "ERROR\n"; //print error
		return 0;
	}
	combo[i] = c;
	
	combo.Print();

	return 0;
}

/*hello world
3
a<b
worhellold
? 10
ERROR*/