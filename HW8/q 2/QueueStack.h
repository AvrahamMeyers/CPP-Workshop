#pragma once
#include "Stack.h"

class Queue
{
public:
    virtual void clear() = 0;
    virtual void enqueue(int value) = 0;
    virtual int dequeue() = 0;
    virtual int front() = 0;
    virtual bool isEmpty() const = 0;
};

class QueueStack : public Queue
{
protected:
    StackList<int>* data;
public:
    QueueStack();
    void clear() override;
    int dequeue() override;
    void enqueue(int value) override;
    int front() override;
    bool isEmpty() const override;
};

QueueStack::QueueStack() {
    data = new StackList<int>;
}

void QueueStack::clear() {
    data->clear();
}

int QueueStack::dequeue() {
    if (data->isEmpty())
        throw "Error:\tQueue is empty\n";

    return data->pop();
}

void QueueStack::enqueue(int value) {
    StackList<int> st;

	while (!data->isEmpty()) {//transferring all of the values in the queue to the other stack
		st.push(data->pop()); //in order to place the new value at the bottom of the stack
	}
	st.push(value);

	while (!st.isEmpty()) {
		data->push(st.pop());
	}

}

int QueueStack::front() {
    if (data->isEmpty())
        throw "Error:\tQueue is empty\n";

    return data->top();
}

bool QueueStack::isEmpty() const {
    return data->isEmpty();
}