/*
LibraryMain.cpp
Allows addition and deletion to a library catalog
CPP Workshop
Homework 9 Question 2
Avraham Meyers
Created on 6.6.21 and Modified on 6.7.21
*/

#include "Book.h"
#include "SearchTree.h"
#include "iostream"

enum {ADD = 'a', REMOVE, SEARCH, PRINT, END};
int main() {
	SearchTree<Book> library;

	char x;
	std::cout << "enter a-e:\n";
	std::cin >> x;
	while (x != END) {
		switch (x) 
		{
		case ADD: {
			std::cout << "enter a book:\n";
			Book b;
			std::cin >> b;
			library.add(b);
			break;
		}
		case REMOVE: {
			std::cout << "enter a book:\n";
			Book b;
			std::cin >> b;
			try {
				library.remove(b);
			}
			catch (const char* message) {
				std::cout << message << std::endl;
			}
			break;
		}
		case SEARCH: {
			std::cout << "enter a book:\n";
			Book b;
			std::cin >> b;
			if (library.search(b))
				std::cout << "exist\n";
			else
				std::cout << "not exist\n";
			break;
		}
		case PRINT: {
			library.inOrder();
			std::cout << '\n';
			break;
		}
		default:
			std::cout << "error\n";
			break;
		}

		std::cout << "enter a-e:\n";
		std::cin >> x;
	}
	return 0;
}
/*enter a-e:
a
enter a book:
1 a a
enter a-e:
a
enter a book:
2 b b
enter a-e:
a
enter a book:
3 c c
enter a-e:
d
1 a a
 2 b b
 3 c c

enter a-e:
b
enter a book:
2 b b
enter a-e:
d
1 a a
 3 c c

enter a-e:
e*/