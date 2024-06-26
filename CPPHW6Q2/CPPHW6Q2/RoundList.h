#pragma once
#include "List.h"

class RoundList : public List {
public:

	RoundList(); 
	RoundList(const RoundList& R); 

	void add(int val);
	void AddtoEnd(int val);
	void removeFirst();

	int search(int n);
	void clear();
};