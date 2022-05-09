#pragma once
# include <vector>
# include "Book.h"
# include<conio.h>

struct Store
{
	Store();
	void add();
	void remove();
	std::vector<Book> sorted_books(int flag, int flag1);
	Book *find(const String&, const int & flag );


private :
	void remove(const Book & b);
	int elem(const Book&);

	bool correct_password()const
	{
		String a;
		std::cout << "Please enter password : \n";
		char b = _getch();
		std::cout << "*";
		a.push_back(b);
		while (b != '\r')
		{
			b = _getch();
			std::cout << "*";
			a.push_back(b);
		}
		return a == password;
	}
	std::vector<Book> books;
	String password;
};

