#include "RoundList.h"

RoundList::RoundList() : List() {}
RoundList::RoundList(const RoundList& R) {
	Link* src, * trg;
	if (R.head == nullptr)
		this->head = nullptr;
	else
	{
		this->head = new Link((R.head)->value, nullptr);
		src = R.head;
		trg = this->head;
		while (src->next != head)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}

		trg->next = head;
	}
}

void RoundList::add(int val) {
	if (isEmpty()) {
		head = new Link(val, head);
		head->next = head;
	}
	else {
		Link* ptr = this->head;
		while (ptr->next != head)
			ptr = ptr->next;

		head = new Link(val, head);
		ptr->next = head;
	}
}

void RoundList::AddtoEnd(int val) {
	if (this->isEmpty())
		add(val);
	else {
		Link* ptr = this->head;
		while (ptr->next != head)
			ptr = ptr->next;
		ptr->next = new Link(val, head);
	}
}

void RoundList::removeFirst() {
	if (isEmpty())
		throw "the List is empty, no Elements to remove";

	Link* ptr = head;

	if (ptr->next == ptr) {
		delete ptr;
		head = nullptr;
	}
	else {
		while (ptr->next != head)
			ptr = ptr->next;

		List::removeFirst();

		ptr->next = head;
	}
}

int RoundList::search(int n) {
	if (isEmpty())
		return -1;
	else {
		Link* ptr = this->head;
		for (int i = 0; i < n; i++)
			ptr = ptr->next;
		return ptr->value;
	}
}

void RoundList::clear() {
	// empty all elements from the List
	Link* next;
	Link* p;
	for (p = this->head->next; p->next != head; p = next)
	{
		// delete the element pointed to by p
		next = p->next;
		p->next = nullptr;
		delete p;
	}

	delete p;
	// mark that the List contains no elements
	p = head;
	delete p;
	head = nullptr;
}