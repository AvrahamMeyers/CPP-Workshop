#pragma once
#include <iostream>

//------------------------------------------------
// class List
// arbitrary size Lists
// permits insertion and removal
// only from the front of the List
//------------------------------------------------
template <typename T>
class List
{
protected:
    //--------------------------------------------
    // inner class link
    // a single element for the linked List
    //--------------------------------------------
    class Link
    {
    public:
        // constructor
        Link(T linkValue, Link* nextPtr);
        Link(const Link&);
        // data areas
        T value;
        Link* next;
    }; //end of class Link

public:
    // constructors
    List();
    List(const List<T>&);
    ~List();
    // operations
    void add(T value);
    T firstElement() const;
    bool search(const T& value) const;
    bool isEmpty() const;
    void removeFirst();
    void clear();
    List<T>& operator=(const List<T>& list);
    void insert(T value);
    void remove(T value);

    //helpers
    T GetValue() { return 0; }

    //friend std::istream& operator>>(std::istream& in, List<T>& list);
    //friend std::ostream& operator<<(std::ostream& out, const List<T>& list);

protected:
    //data field
    Link* head;
};

//------------------------------------------------
// class Link implementation
//------------------------------------------------
template <typename T>
List<T>::Link::Link(T val, Link* nxt) : value(val), next(nxt) {}
template <typename T>
List<T>::Link::Link(const Link& source) : value(source.value), next(source.next) {}
//--------------------------------------------
// class List implementation
//--------------------------------------------
template <typename T>
List<T>::List() : head(nullptr)
{}
template <typename T>
List<T>::List(const List<T>& l)
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
template <typename T>
List<T>::~List()
{
    clear();
}
template <typename T>
void List<T>::clear()
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
template <typename T>
bool List<T>::isEmpty() const
{
    // test to see if the List is empty
    // List is empty if the pointer to the head
    // Link is null
    return head == nullptr;
}
template <typename T>
void List<T>::removeFirst()
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
/*
template <typename T>
std::istream& operator>>(std::istream& in, List<T>& list) {
    T value;
    in >> value;
    list.add(value);

    T value2;
    for (List<T>::Link* p = list.head; p != nullptr; p = p->next) {
        in >> value2;
        if (value2 >= value)
            break;
        p->next = new List<T>::Link(value2, nullptr);
        value = value2;
    }

    return in;
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& list) {
    for (List<T>::Link* p = list.head; p != nullptr; p = p->next) {
        out << p->value << ' ';
    }

    return out;
}*/

template <typename T>
List<T>& List<T>::operator=(const List<T>& list) {
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

template <typename T>
void List<T>::add(T val)
{
    //Add a new value to the front of a Linked List
    head = new Link(val, head);
    if (head == nullptr)
        throw "failed in memory allocation";
}
template <typename T>
T List<T>::firstElement() const
{
    // return first value in List
    if (isEmpty() != true)
        //throw "the List is empty, no first Element";
        return this->head->value;
}
template <typename T>
bool List<T>::search(const T& val) const
{
    // loop to test each element
    for (Link* p = this->head; p != nullptr; p = p->next)
        if (val == p->value)
            return true;
    // not found
    return false;
}
template <typename T>
void List<T>::insert(T value) {
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

        List<T>::Link* node = new Link(value, p->next);
        p->next = node;
    }
}
template <typename T>
void List<T>::remove(T value) {
    if (this->isEmpty())
        throw "value not found\n";

    else if (this->search(value) == false)
        throw "value not found\n";

    else if (this->head->value == value) {
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
