#include "List.h"
#include <iostream>

//------------------------------------------------
// class Link implementation
//------------------------------------------------
List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {}
List::Link::Link(const Link& source) : value(source.value), next(source.next) {}
//--------------------------------------------
// class List implementation
//--------------------------------------------
List::List() : head(nullptr)
{}
List::List(const List& l)
{
	Link* src, * trg;
	if (l.head == nullptr)
		this->head = nullptr;
	else
	{
		this->head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = this->head;
		while (src->next != nullptr)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
}
List::~List()
{
	clear();
}
void List::clear()
{
	// empty all elements from the List
	Link* next;
	for (Link* p = this->head; p != nullptr; p = next)
	{
		// delete the element pointed to by p
		next = p->next;
		p->next = nullptr;
		delete p;
	}
	// mark that the List contains no elements
	head = nullptr;
}

bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == nullptr;
}
void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}
int List::firstElement() const
{
	// return first value in List
	if (isEmpty() != true)
		//throw "the List is empty, no first Element";
		return this->head->value;
}

bool List::search(const int& val) const
{
	// loop to test each element
	for (Link* p = this->head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}
void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;
}

std::istream& operator>>(std::istream& in, List& list) {
	int value;
	in >> value;
	list.add(value);

	int value2;
	for (List::Link* p = list.head; p != nullptr; p = p->next) {
		in >> value2;
		if (value2 >= value)
			break;
		p->next = new List::Link(value2, nullptr);
		value = value2;
	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const List& list) {
	for (List::Link* p = list.head; p != nullptr; p = p->next) {
		out << p->value << ' ';
	}

	return out;
}

List& List::operator=(const List& list) {
	this->clear();

	Link* src, * trg;
	if (list.head == nullptr)
		this->head = nullptr;
	else
	{
		this->head = new Link((list.head)->value, nullptr);
		src = list.head;
		trg = this->head;
		while (src->next != nullptr)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}

	return *this;
}

void List::insert(int value) {
	if (this->head == nullptr) {
		this->add(value);
		return;
	}
	if (this->head->value < value) {
		this->add(value);
		return;
	}
	else {
		Link* p;
		for (p = this->head; p->next != nullptr && (p->next)->value > value; p = p->next);

		List::Link* node = new Link(value, p->next);
		p->next = node;
	}
}

void List::remove(int value) {
	if (this->isEmpty())
		throw "value not found\n";

	if (this->search(value) == false)
		throw "value not found\n";

	if (this->head->value == value) {
		this->removeFirst();
	}
	else {
		Link* p;
		for (p = this->head; p->next != nullptr && (p->next)->value != value; p = p->next);

		if (p->next == nullptr) {
			throw "end of list\n";
		}
		
		else {
			Link* t = p->next;
			p->next = p->next->next;
			delete t;
		}
	}
}

