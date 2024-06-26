/*
HW5Q2ListMain.cpp
Merges two linked lists and turns it into a set, and reverses its elements
CPP Workshop
Homework 5 Question 2
Avraham Meyers
Created on 4.27.21 and Modified on 4.27.21
*/

#include "List.h"
#include <iostream>

List merge(List lst1, List lst2) {
	List* merged = new List();

	int t = lst1.firstElement(),
		s = lst2.firstElement();

	while (lst1.isEmpty() == false && lst2.isEmpty() == false) {
		if (t >= s) {
			merged->insert(t);
			lst1.removeFirst();
			t = lst1.firstElement();
		}
		else if (t == s) {
			merged->insert(t);
			merged->insert(s);
			lst1.removeFirst();
			lst2.removeFirst();
			t = lst1.firstElement();
			s = lst2.firstElement();
		}

		else {
			merged->insert(s);
			lst2.removeFirst();
			s = lst2.firstElement();
		}
	}
	if (lst1.isEmpty()) {
		while (lst2.isEmpty() == false) {
			merged->insert(lst2.firstElement());
			lst2.removeFirst();
		}
	}
	else if (lst2.isEmpty()) {
		while (lst1.isEmpty() == false) {
			merged->insert(lst1.firstElement());
			lst1.removeFirst();
		}
	}

	return *merged;
}

void makeSet(List& list) {
	List* Set = new List(); //making a new list that will hold the Set version of the list

	int element = list.firstElement();
	list.removeFirst();
	Set->insert(element);

	int element2;
	for (; list.isEmpty() != true; list.removeFirst()) {
		element2 = list.firstElement();
		if (element2 != element) {
			Set->insert(element2);
			element = element2;
		}
	}

	list = *Set;
	delete Set; //deleting the Set because it was copied into the list that was passed
}

void reverse(List& list) {
	List* reverse = new List();

	for (; list.isEmpty() != true; list.removeFirst()) {
		reverse->add(list.firstElement());
	}

	list = *reverse;
	delete reverse;
}

int main()
{
	List lst1, lst2, mergedList;

	std::cout << "enter sorted values for the first list:" << std::endl;
	std::cin >> lst1;
	std::cout << "enter sorted values for the second list:" << std::endl;
	std::cin >> lst2;

	mergedList = merge(lst1, lst2);
	std::cout << "the new merged list: " << mergedList << std::endl;

	makeSet(mergedList);
	std::cout << "the new merged set: " << mergedList << std::endl;

	reverse(mergedList);
	std::cout << "the new merged reverse: " << mergedList << std::endl;


	return 0;
}

/*
enter sorted values for the first list:
6 5 4 3 2 9
enter sorted values for the second list:
7 5 4 3 9
the new merged list: 7 6 5 5 4 4 3 3 2
the new merged set: 7 6 5 4 3 2
the new merged reverse: 2 3 4 5 6 7
*/