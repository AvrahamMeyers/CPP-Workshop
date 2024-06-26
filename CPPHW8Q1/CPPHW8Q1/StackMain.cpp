/*
StackMain.cpp
calculates an expression given in infix form
CPP Workshop
Homework 8 Question 1
Avraham Meyers
Created on 13.5.21 and Modified on 18.5.21
*/

#include "Stack.h"
#include <iostream>
#include <string.h>

int ctoi(char c);
//takes a char (assumed to be a number) and converts it to its integer value
bool isOperator(char c);
//returns true if c is an operator
bool isNumber(char c);
//returns true if c is a number
std::string InfixtoPostfix(std::string Infix);
//accepts a string representing an infix expression
//and converts it to the postfix form
float CalcPostFix(std::string Infix);
//accepts a string representing a string in postfix form
// and returns the result of the calculation

int main()
{
	std::string exp;
	std::cout << "enter an infix expression as a string" << std::endl;
	std::cin >> exp;
	std::string postfix = InfixtoPostfix(exp);
	std::cout << postfix << std::endl;
	std::cout << CalcPostFix(postfix) << std::endl;
	return 0;
}
/*
enter an infix expression as a string
(5+3)*((20/10)+(8-6))
 5 3 + 20 10 / 8 6 - + *
32
*/

int ctoi(char c) {
	return c - '0';
}

int precedence(char c) {
	if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return 0;
}

bool isOperator(char c) {
	if (c == '*' || c == '/'
		|| c == '+' || c == '-')
		return true;
	else
		return false;
}

bool isNumber(char c) {
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}

std::string InfixtoPostfix(std::string Infix) {
	StackList<char> st;
	std::string result;

	for (int i = 0; i < Infix.length(); i++) {
		char c = Infix[i];

		if (c == '(')
			st.push(c);

		else if (c == ')') {
			while (!st.isEmpty() && st.top() != '(') {
				char temp = st.top();
				st.pop();
				result += ' ';
				result += temp;
			}
			st.pop();	
		}
		else if (isNumber(c)) {
			char previous = Infix[i - 1];
			if (previous < '0' || previous > '9') // if the previous char was not a number 
				result += ' '; //then put a space before the new number
			result += c;
		}
		else if (isOperator(c)) {
			while (precedence(st.top()) > precedence(c)) {
				result += ' ';
				char temp = st.top();
				st.pop();
				result += temp;
			}
			st.push(c);
		}
	}
	while (!st.isEmpty()) {
		char temp = st.top();
		st.pop();
		result += ' ';
		result += temp;
	}

	return result;
}

float CalcPostFix(std::string Infix) {
	StackList<float> st;

	for (int i = 0; i < Infix.length(); i++) {
		char c = Infix[i];

		if (isNumber(c)) {
			int number = ctoi(c);
			while (Infix[i + 1] != ' ') {//checking if the current digit is part of a longer number
				int onesplace = ctoi(Infix[++i]);
				number = (10 * number) + onesplace;
			}
			st.push(number);
		}

		else if (isOperator(c)) {
			float operand1 = st.top();
			st.pop();
			float operand2 = st.top();
			st.pop();
			float result = 0;
			if (c == '+')
				result += operand1 + operand2;
			else if (c == '-')
				result += operand2 - operand1;
			else if (c == '*')
				result += operand1 * operand2;
			else if (c == '/')
				result += operand2 / operand1;

			st.push(result);
		}
	}

	float result = st.top();
	st.pop();
	return result;

}

