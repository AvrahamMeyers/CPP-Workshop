#include "String.h"
#include <cstring>
#include <iostream>

void String::Print() {
	std::cout << this->data << std::endl;
}

String::String(const char* p) {//constructor
	this->len = strlen(p);
	this->data = new char[this->len + 1];
	strcpy_s(this->data, this->len + 1, p);
}

bool String::operator>(const String& s) {
	int comparison = strcmp(this->data, s.data);//comparing the two strings
	
	if (comparison > 0)
		return true;
	else
		return false;
}

bool String::operator>=(const String& s) {
	int comparison = strcmp(this->data, s.data);

	if (comparison >= 0)
		return true;
	else
		return false;
}

bool String::operator<(const String& s) {
	int comparison = strcmp(this->data, s.data);

	if (comparison < 0)
		return true;
	else
		return false;
}

bool String::operator<=(const String& s) {
	int comparison = strcmp(this->data, s.data);

	if (comparison <= 0)
		return true;
	else
		return false;
}

bool String::operator!=(const String& s) {
	if (this->len != s.len)//if the two lengths are not the same, then the two strings are not equal
		return false;

	int comparison = strcmp(this->data, s.data);

	if (comparison == 0)
		return true;
	else
		return false;
}

char& String::operator[](int x) {
	
	return *(this->data + x);//returning the reference to the desired subscript in the string
}

String String::insert(int index, const char* s) {
	if (index > this->len) {
		std::cout << "ERROR\n";
		String empty;
		return empty;
	}
	
	String combo;
	combo.len = this->len + strlen(s) + 1;
	char* p = combo.data;//deleting the previous array designated for combo
	delete p;
	combo.data = new char[combo.len];

	for (int i = 0; i < index; i++) {//copying the first letters into combo
		combo.data[i] = this->data[i];
	}

	for (int i = index; i < index + strlen(s); i++)//copying the insert word into combo
		combo.data[i] = s[i - index];

	for (int i = index + strlen(s), j = index; i < combo.len; i++, j++) {//copying the end of the first word into combo
		combo.data[i] = this->data[j];
	}

	combo.data[combo.len - 1] = '\0';//putting the end character at the end of the string

	return combo;
}