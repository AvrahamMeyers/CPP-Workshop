/*
QueueStackMain.cpp
Implements a queue using a stack and a helper stack
CPP Workshop
Homework 8 Question 2
Avraham Meyers
Created and Modified on 20.5.21
*/

#include <iostream>
#include "QueueStack.h"


int main() {
	Queue* Q;
	Q = new QueueStack();
	try {
		for (int i = 0; i < 10; i++)
			Q->enqueue(i);
	}
	catch (const char* msg)
	{
		std::cout << msg;
	}
	std::cout << "first on Q is: " << Q->front() << std::endl;
	std::cout << "take out 2 elements:" << std::endl;
	std::cout << Q->dequeue() << ' ' << Q->dequeue() << std::endl;
	std::cout << "first on Q is: " << Q->front() << std::endl;
	Q->enqueue(8);
	Q->enqueue(9);
	while (!Q->isEmpty())
		std::cout << Q->dequeue() << " ";
	return 0;
}

/*
first on Q is: 0
take out 2 elements:
1 0
first on Q is: 2
2 3 4 5 6 7 8 9 8 9
*/
