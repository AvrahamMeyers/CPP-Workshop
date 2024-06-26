#pragma once

class Vector {
	int* data;
	int capacity;
	int size;

public:
	int GetCapacity() { return this->capacity; }
	int GetSize() { return this->size; }

	Vector(int capacity) { //constructor
		this->capacity = capacity;
		this->data = new int[this->capacity];
		this->size = 0;
	}

	Vector() : Vector(2) {}//default constructor
	
	Vector(const Vector& V) {//copy constructor
		this->capacity = V.capacity;
		this->data = new int[this->capacity];
		for (int i = 0; i < V.size; i++)
			this->data[i] = V.data[i];
		this->size = V.size;
	}

	~Vector() { delete[] this->data; } //destructor

	void print();
	bool isEqual(Vector& V);
	int strcatcat(Vector& V);
	int& at(int index);
	void assign(const Vector& V);
	Vector strnewcat(Vector& V);
	void insert(int val);
	void clear();
	void delLast();
};