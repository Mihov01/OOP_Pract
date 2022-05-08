#pragma once
# include "BookList.h"
# include<conio.h>

struct Store
{
	Store();
	void add();
	void remove();
	BookList sorted_books(int flag, int flag1);
	Book *find(const String&, const int & flag );


private :
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
	BookList books;
	String password;
};

