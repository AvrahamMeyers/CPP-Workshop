#pragma once

class String {
	int len = 0; 
	char* data;

public:
	void Print();
	int getLen() { return this->len; }

	String(const char* p);//constructor
	String() : String("") {}; //default constructor
	String(const String& s) : String(s.data) {};//copy constructor
	~String() { delete[] data; }//destructor

	bool operator>(const String& s);
	bool operator<(const String& s);
	bool operator>=(const String& s);
	bool operator<=(const String& s);
	bool operator!=(const String& s);

	char& operator[](int x);

	String insert(int index, const char* s);
};