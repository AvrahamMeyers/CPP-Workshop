#pragma once
#include <iostream>

//------------------------------------------------
// class List
// arbitrary size Lists
// permits insertion and removal
// only from the front of the List
//------------------------------------------------
class List
{
private:
    //--------------------------------------------
    // inner class link
    // a single element for the linked List
    //--------------------------------------------
    class Link
    {
    public:
        // constructor
        Link(int linkValue, Link* nextPtr);
        Link(const Link&);
        // data areas
        int value;
        Link* next;
    }; //end of class Link

public:
    // constructors
    List();
    List(const List&);
    ~List();
    // operations
    void add(int value);
    int firstElement() const;
    bool search(const int& value) const;
    bool isEmpty() const;
    void removeFirst();
    void clear();
    List& operator=(const List& list);
    void insert(int value);
    void remove(int value);

    //helpers
    int GetValue() { return 0; }

    friend std::istream& operator>>(std::istream& in, List& list);
    friend std::ostream& operator<<(std::ostream& out, const List& list);

private:
    //data field
    Link* head;
};