# include "Booklist.h"
#include <stdexcept>
void merge(Book **array, int const left, int const mid, int const right, int flag, int flag1)
{
	// flag1 determines if it should return < or >
   // flag determines if it should return comparison by title , author or isbn
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	Book** leftArray;
		Book ** rightArray;
	leftArray = new Book * [subArrayOne];
	rightArray = new Book*[subArrayTwo];


	for (int i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (int j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	int indexOfSubArrayOne = 0,
		indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;


	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]->smaller_by(*(rightArray[indexOfSubArrayTwo]), flag, flag1)) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}


void mergeSort(Book ** array, int const begin, int const end, int flag, int flag1)
{
	if (begin >= end)
		return;

	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid, flag, flag1);
	mergeSort(array, mid + 1, end, flag, flag1);
	merge(array, begin, mid, end, flag, flag1);
}
BookList BookList:: sort(int flag, int flag1)
{
	
	BookList a;
	a.copy(this->book, this->size, this->capacity);
	mergeSort(a.book, 0, size-1, flag, flag1);
	return a;
}
BookList::BookList()
{
	try
	{
		this->book = new Book*[capacity];
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}
BookList::BookList(const BookList& other)
{
	try
	{
		book = new Book *[other.capacity];
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
	Book* temp = new Book(b);
	this->book[size++] = temp;
}
void BookList::pop()
{
	if (size != 0)
	{
		delete book[size-1];
		size--;
	}
}
Book* BookList ::operator[](const unsigned int& i)
{
	return book[i];
}
Book* BookList ::operator[](const unsigned int& i)const 
{
	return book[i];
}
int BookList::elem( Book* b)
{
	
	
	for (int i = 0; i < size; i++)
	{
		if (book[i] ->equal (b)) return i;
		book[i]->Print();
	}
	return -1;
}
void BookList::remove( Book* b)
{
	int ind = elem(b);
	if (ind  != -1)
	{
		for (int i = 0; i < size-1; i++)
		{
			std::swap(book[i], book[i+1]);
		}
		pop();
	}
}
bool BookList::reserve(int size1)
{
	try
	{
		Book** temp = new Book*[size1];
		int s = this->size;
		for (int i = 0; i < s; i++)
		{
			temp[i] = new Book (*book[i]);
		}
		free();
		this->size = s;
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
	free();
}
void BookList::print()const
{

	for (int i = 0; i < size; i++)
	{
	 book[i]->Print();
		std::cout << "\n";
	}
}
BookList & BookList ::operator =(const BookList& other)
{
	if (this != &other)
	{
		copy(other.book, other.size, other.capacity);
		
	}
	return *this;
}
