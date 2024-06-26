/*
TreeMain.cpp
Offers the user multiple operations to perform on a binary search tree
CPP Workshop
Homework 9 Question 1
Avraham Meyers
Created on 26.5.21 and Modified on 2.6.21
*/
#include "SearchTree.h"
#include <iostream>
using namespace std;
enum { END, ADD, SEARCH, REMOVE, BREADTHSCAN, HEIGHT, SUCCESSOR, DELETEDUP, REFLECT };
int main()
{
	SearchTree<int> T1;
	cout << "enter 10 numbers:\n";
	int x, y, z;
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		T1.add(x);
	}
	cout << "inorder: ";
	T1.inOrder();
	cout << "\nenter 0-8:\n";
	cin >> x;
	while (x != END)
	{
		switch (x)
		{
		case ADD: cout << "enter a number: ";
			cin >> y;
			T1.add(y);
			cout << "after adding " << y << ": ";
			T1.inOrder();
			cout << endl;
			break;
		case SEARCH: cout << "enter a number: ";
			cin >> y;
			if (T1.search(y))
				cout << "exist" << endl;
			else
				cout << "no exist" << endl;
			break;
		case REMOVE:cout << "enter a number: ";
			cin >> y;
			try
			{
				T1.remove(y);
				cout << "after removing " << y << ": ";
				T1.inOrder();
				cout << endl;
			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			break;
		case BREADTHSCAN: cout << "breadth scan: ";
			T1.BreadthScan();
			cout << endl;
			break;
		case HEIGHT:cout << "height of tree: " << T1.height() << endl;
			break;
		case SUCCESSOR:cout << "enter a number: ";
			cin >> y;
			try
			{
				z = T1.successor(y);
				cout << "successor of " << y << " is: " << z << endl;
			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			break;
		case DELETEDUP: cout << "after delete duplicate: ";
			T1.deleteDuplicates();
			T1.inOrder();
			cout << endl;
			break;
		case REFLECT:T1.reflect();
			cout << "reflected tree: ";
			T1.inOrder();
			T1.reflect();
			cout << endl;
			break;
		}
		cout << "enter 0-8:\n";
		cin >> x;
	}
	return 0;
}
/*enter 10 numbers:
1 2 3 4 5 1 2 3 4 5
inorder: 1 1 2 2 3 3 4 4 5 5
enter 0-8:
6
enter a number: 5
no successor

enter 0-8:
6
enter a number: 4
successor of 4 is: 5
enter 0-8:
6
enter a number: 3
successor of 3 is: 4
enter 0-8:
6
enter a number: 2
successor of 2 is: 3
enter 0-8:
6
enter a number: 1
successor of 1 is: 2
enter 0-8:
7
after delete duplicate: 1 2 3 4 5
enter 0-8:
8
reflected tree: 5 4 3 2 1
enter 0-8:
1
enter a number: 6
after adding 6: 1 2 3 4 5 6
enter 0-8:
2
enter a number: 4
exist
enter 0-8:
2
enter a number: 7
no exist
enter 0-8:
4
breadth scan: 1 2 3 4 5 6
enter 0-8:
5
height of tree: 5
enter 0-8:
6
enter a number: 5
successor of 5 is: 6
enter 0-8:
7
after delete duplicate: 1 2 3 4 5 6
enter 0-8:
8
reflected tree: 6 5 4 3 2 1
enter 0-8:
0*/
