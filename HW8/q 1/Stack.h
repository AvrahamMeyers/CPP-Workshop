#pragma once
#include "ListTemplate.h"
//-------------------------------------------------------
// class stack
// abstract class - simply defines protocol for
// stack operations
//-------------------------------------------------------
template <typename T>
class Stack
{
public:
	virtual void clear() = 0;
	virtual bool isEmpty() const = 0;
	virtual T pop() = 0;
	virtual void push(T value) = 0;
	virtual T top() = 0;
};

//-------------------------------------------------------
// class StackList
// Stack implemented using List operations
//-------------------------------------------------------
template <typename T>
class StackList : public Stack<T>
{
public:
	StackList();
	StackList(const StackList<T>&);
	// Stack operations
	void clear()override;
	bool isEmpty() const override;
	T pop()override;
	void push(T value) override;
	T top()override;
protected:
	// data fields
	List<T> data;
}; 

//-------------------------------------------------------
// class StackList implementation
//-------------------------------------------------------
template <typename T>
StackList<T>::StackList() :data()
{
	// create and initialize a Stack based on Lists
}
template <typename T>
StackList<T>::StackList(const StackList<T>& lst)
	: data(lst.data)
{ /* copy constructor*/
}
template <typename T>
void StackList<T>::clear()
{
	// clear all elements from Stack, by setting
	// delete all values from List
	data.clear();
}
template <typename T>
bool StackList<T>::isEmpty() const
{ // return true if Stack is empty
	return data.isEmpty();
}
template <typename T>
T StackList<T>::pop()
{
	// return and remove the intopmost element in the Stack
	// get first element in List
	T result = data.firstElement();
	// remove element from List
	data.removeFirst();
	// return value
	return result;
}
template <typename T>
void StackList<T>::push(T val)
{
	// push new value onto Stack
	data.add(val);
}
template <typename T>
T StackList<T>::top()
{
	return data.firstElement();
}
