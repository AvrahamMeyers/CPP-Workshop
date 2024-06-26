#pragma once
#include <string>
#include <iostream>

class Book {
private:
	int BookNumber;
	std::string author;
	std::string BookName;

public:
	Book();
	bool operator<(Book& book);
	bool operator>(Book& book);
	bool operator<=(Book& book);
	bool operator>=(Book& book);
	bool operator==(Book& book);
	bool operator!=(Book& book);

	friend std::ostream& operator<<(std::ostream& out, Book& b);
	friend std::istream& operator>>(std::istream& in, Book& b);
};

Book::Book() : BookNumber(0), author(""), BookName("") {}

bool Book::operator<(Book& book) {
	if (this->author < book.author)
		return true;

	if (this->author > book.author)
		return false;

	if (this->BookName < book.BookName)
		return true;

	if (this->BookName > book.BookName)
		return false;

	if (this->BookNumber < book.BookNumber)
		return true;

	if (this->BookNumber > book.BookNumber)
		return false;

	return false;
}

bool Book::operator>(Book& book) {
	if (this->author > book.author)
		return true;

	if (this->author < book.author)
		return false;

	if (this->BookName > book.BookName)
		return true;

	if (this->BookName < book.BookName)
		return false;

	if (this->BookNumber > book.BookNumber)
		return true;

	if (this->BookNumber < book.BookNumber)
		return false;

	return false;
}

bool Book::operator<=(Book& book) {
	if (*this < book || *this == book)
		return true;
	else
		return false;
}

bool Book::operator>=(Book& book) {
	if (*this > book || *this == book)
		return true;
	else
		return false;
}

bool Book::operator==(Book& book) {
	if (this->author != book.author)
		return false;
	if (this->BookNumber != book.BookNumber)
		return false;
	if (this->BookName != book.BookName)
		return false;
	return true;
}

bool Book::operator!=(Book& book) {
	if (this->author == book.author)
		return false;
	if (this->BookNumber == book.BookNumber)
		return false;
	if (this->BookName == book.BookName)
		return false;
	return true;
}

std::ostream& operator<<(std::ostream& out, Book& b) {
	out << b.BookNumber << ' ' 
		<< b.author << ' ' 
		<< b.BookName << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Book& b) {
	in >> b.BookNumber >> b.author >> b.BookName;
	return in;
}