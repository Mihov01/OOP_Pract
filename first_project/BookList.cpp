# include "Booklist.h"
#include <stdexcept>
BookList::BookList()
{
	try
	{
		this->book = new Book[capacity];
	}
	catch (const std::exception& e)
	{
		throw;
	}
}
BookList::BookList(const BookList& other)
{
	try
	{
		book = new Book[other.capacity];
		int size = other.size;
		for (int i = 0; i < size; i++)
		{
			this->book[i] = other.book[i];
		}
		this->size = other.size;
		this->capacity = other.capacity;
	}
	catch (const std::exception& e)
	{
		throw;
	}
}

void BookList::push(const Book & b)
{
	if (this->capacity == this->size)
	{
		resize();
	}
	this->book[size++] = b;
}
void BookList::pop()
{
	this->size--;
}
Book& BookList ::operator[](const unsigned int& i)
{
	return book[i];
}
Book& BookList ::operator[](const unsigned int& i)const
{
	return book[i];
}
int BookList::elem(const Book& b)
{
	int ind = -1;
	for (int i = 0; i < size; i++)
	{
		if (book[i] == b) ind = i;
	}
	return ind;
}
void BookList::remove(const Book& b)
{
	int ind = elem(b);
	if (ind  != -1)
	{
		for (int i = ind; i < size - 1; i++)
		{
			std::swap(book[i], book[i + 1]);
		}
		pop();
	}
}
bool BookList::reserve(int size1)
{
	try
	{
		Book* temp = new Book[size1];
		int s = this->size;
		for (int i = 0; i < s; i++)
		{
			temp[i] = book[i];
		}
		delete[]book;
		this->book = temp;
		capacity = size1;
	}
	catch (const std::exception& e)
	{
		return false;
	}
	return true;
}
int BookList::Size()const
{
	return this->size;
}
BookList::~BookList()
{
	delete[] book;
}
void BookList::print()const
{

	for (int i = 0; i < size; i++)
	{
		std::cout << book[i] << "\n";
	}
}