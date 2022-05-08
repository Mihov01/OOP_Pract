#pragma once
# include "Book.h"
# include <vector>
struct BookList {
	BookList();
	BookList(const BookList& books);
	void push(const Book&);
	void pop();
	Book &operator[] (const unsigned int&);

	BookList& operator = (const BookList&);
	int elem( const Book&);
	void remove(const  Book&);
	void reserve(int);
	int size()const;
	BookList sort(int flag, int flag1);
	~BookList();
	void print() const;
private :
	std::vector<Book> list;
};