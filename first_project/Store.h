#pragma once
# include <vector>
# include "Book.h"

struct Store
{
	Store(String& password);
	void add();
	void remove();
	std::vector<Book> sorted_books(compare& flag, compare_by & flag1);
	Book *find(const String&, compare_by & flag );


private :
	void remove(const Book & b);
	int elem(const Book&);
	bool correct_password()const;
	std::vector<Book> books;
	String password;
};

