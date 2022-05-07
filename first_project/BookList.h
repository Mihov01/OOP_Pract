#pragma once
# include "Book.h"

struct BookList {
	BookList();
	BookList(const BookList& books);
	void push(const Book&);
	void pop();
	Book& operator[] (const unsigned int&);
	Book& operator[] (const unsigned int&) const ;
	int elem(const Book&);
	void remove(const Book&);
	bool reserve(int);
	int Size()const;
	~BookList();
	void print() const;
private :
	void resize()
	{
		Book* temp = new Book[capacity * 2];
		for (int i = 0; i < size; i++)
		{
			temp[i] = book[i];
		}
		delete[]book;
		this->capacity *= 2;
		this->book = temp;
		temp = nullptr;
	}
	int size = 0;
	int capacity = 8;
	Book* book = nullptr;
};