#pragma once
# include "Book.h"

struct BookList {
	BookList();
	BookList(const BookList& books);
	void push(const Book&);
	void pop();
	Book* operator[] (const unsigned int&);
	Book* operator[] (const unsigned int&) const ;
	BookList& operator = (const BookList&);
	int elem( Book*);
	void remove( Book*);
	bool reserve(int);
	int Size()const;
	BookList sort(int flag, int flag1);
	~BookList();
	void print() const;
private :
	void resize()
	{
		Book** temp = new Book*[capacity * 2];
		for (int i = 0; i < size; i++)
		{
			temp[i] = book[i];
		}
		delete[]book;
		this->capacity *= 2;
		this->book = temp;
		temp = nullptr;
	}
	void copy(Book** arr, int _size, int _capacity)
	{
		free();
		this->book = new Book * [_capacity];
		for (int i = 0; i < _size; i++)
		{
			book[i] = new Book(*arr[i]);
		} 
		this->size = _size;
		this->capacity = _capacity;
	}
	void free()
	{
		for (int i = 0; i < size; i++)
		{
			delete book[i];
		}

		delete[] book;
		book = nullptr;
		size = 0;
	}
	int size = 0;
	int capacity = 8;
	Book** book = nullptr;
};