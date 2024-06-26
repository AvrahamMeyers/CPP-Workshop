#include "Vector.h"
#include <iostream>

void Vector::print() {
	std::cout << "capacity: " << this->capacity << ' '
		<< "size: " << this->size << ' '
		<< "values: ";
	for (int i = 0; i < this->size; i++)
		std::cout << this->data[i] << ' ';
	std::cout << std::endl;
}

bool Vector::isEqual(Vector& V) {
	if (this->size != V.size)
		return false;

	for (int i = 0; i < this->size; i++) {
		if (this->data[i] != V.data[i]) 
			return false;
	}
	return true;
}

int Vector::strcatcat(Vector& V) {
	if (this->size != V.size) {
		std::cout << "ERROR\n";
		return -1;
	}

	int dotproduct = 0;
	for (int i = 0; i < this->size; i++)//looping through the vector
		dotproduct += this->data[i] * V.data[i];//adding the product of the current index in the two 
											//vectors to the dotproduct
	return dotproduct;
}

int& Vector::at(int index) {	
	if (index >= this->capacity || index < 0) {
		std::cout << "ERROR\n";
		return *this->data; 
	}

	else
		return *(this->data + index);//returning the address of the index of the vector
}

void Vector::assign(const Vector& V) {
	delete[] this->data;//deleting the previous content of the vector

	this->capacity = V.capacity;
	this->size = V.size;
	this->data = new int[this->capacity];//allocating a new array for the vector with the new capacity
	for (int i = 0; i < this->size; i++)
		this->data[i] = V.data[i];//copying the elements from V to the vector
}

Vector Vector::strnewcat(Vector& V) {
	Vector newcat(this->capacity + V.capacity);//declaring a new vector with the capacity and
	newcat.size = this->size + V.size;//size of the passed Vector
	for (int i = 0; i < this->size; i++)
		newcat.data[i] = this->data[i];//copying the values from the vector to the new vector

	for (int i = 0; i < V.size; i++)//copying the values from the passed vector to the new vector
		newcat.data[i + this->size] = V.data[i];//with an offset equal to the size of the local vector

	return newcat;
}

void Vector::insert(int val) {
	if (this->size < this->capacity) {//if the size of the vector is less than the capacity
		this->data[this->size] = val;//then there is room for the new value in the vector
		this->size++;
	}

	else {//if not, the vector must be doubled in size
		int* tempptr = this->data;
		this->capacity *= 2;
		this->data = new int[this->capacity];
		for (int i = 0; i < this->size; i++)
			this->data[i] = tempptr[i];

		this->data[this->size] = val;
		this->size++;
		delete[] tempptr;
	}
}

void Vector::clear() {
	this->size = 0;
}

void Vector::delLast() {
	if (this->size == 0) {
		std::cout << "ERROR\n";
		return;
	}

	else
		this->size--;
}