/*
VectorMain.cpp
Performs common vector operations on three vectors
CPP Workshop
Homework 2 Question 2
Avraham Meyers
Created and Modified on 3.17.21
*/

#include "Vector.h"
#include <iostream>
using namespace std;
enum options
{
	stop, assignment, isEqual, mult, add, clear, delLast, at, insert
};
int main()
{
	Vector  v1(10), v2(10), v3;
	for (int i = 1; i <= 4; i++)
	{
		v1.insert(i);
		v2.insert(i + 4);
	}
	int choice, val, index;
	cout << "enter your choice 0-8:\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case assignment: v3.assign(v1);
			break;
		case isEqual:	if (v1.isEqual(v2)) cout << "v1==v2\n"; else cout << "v1!=v2\n";
			break;
		case mult:		cout << "v1*v2=" << v1.strcatcat(v2) << endl;
			break;
		case add:		v3.assign(v1.strnewcat(v2));
			break;
		case clear:		v1.clear();
			break;
		case delLast:	       v2.delLast();
			break;
		case at:		cout << "enter index:" << endl; cin >> index; cout << "enter value:" << endl; cin >> val; v3.at(index) = val;
			break;
		case insert:	cout << "enter value:" << endl; cin >> val; v3.insert(val);
			break;
		default: cout << "ERROR";
		}
		v1.print();		v2.print();		v3.print();
		cout << "enter your choice 0-8:\n";
		cin >> choice;
	}
	return 0;
}

/*
enter your choice 0-8:
4
capacity: 10 size: 4 values: 1 2 3 4
capacity: 10 size: 4 values: 5 6 7 8
capacity: 20 size: 8 values: 1 2 3 4 5 6 7 8
enter your choice 0-8:
2
v1!=v2
capacity: 10 size: 4 values: 1 2 3 4
capacity: 10 size: 4 values: 5 6 7 8
capacity: 20 size: 8 values: 1 2 3 4 5 6 7 8
enter your choice 0-8:
1
capacity: 10 size: 4 values: 1 2 3 4
capacity: 10 size: 4 values: 5 6 7 8
capacity: 10 size: 4 values: 1 2 3 4
enter your choice 0-8:
3
v1*v2=70
capacity: 10 size: 4 values: 1 2 3 4
capacity: 10 size: 4 values: 5 6 7 8
capacity: 10 size: 4 values: 1 2 3 4
enter your choice 0-8:
5
capacity: 10 size: 0 values:
capacity: 10 size: 4 values: 5 6 7 8
capacity: 10 size: 4 values: 1 2 3 4
enter your choice 0-8:
6
capacity: 10 size: 0 values:
capacity: 10 size: 3 values: 5 6 7
capacity: 10 size: 4 values: 1 2 3 4
enter your choice 0-8:
7
enter index:
2
enter value:
7
capacity: 10 size: 0 values:
capacity: 10 size: 3 values: 5 6 7
capacity: 10 size: 4 values: 1 2 7 4
enter your choice 0-8:
8
enter value:
10
capacity: 10 size: 0 values:
capacity: 10 size: 3 values: 5 6 7
capacity: 10 size: 5 values: 1 2 7 4 10
enter your choice 0-8:
0
*/
