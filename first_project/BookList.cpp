# include "Booklist.h"
#include <stdexcept>
# include <algorithm>
int partition(std::vector<Book> &arr, int start, int end, int flag , int flag1 )
{

	Book pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] .smaller_by (pivot, flag , flag1))
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	std::swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i].smaller_by(pivot, flag, flag1)) {
			i++;
		}

		while (!arr[i].smaller_by(pivot, flag, flag1)) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			std::swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(std::vector<Book> &arr, int start, int end, int flag , int flag1)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end, flag , flag1);

	// Sorting the left part
	quickSort(arr, start, p - 1, flag, flag1);

	// Sorting the right part
	quickSort(arr, p + 1, end, flag , flag1);
}

void merge(std::vector<Book> & array, int const left, int const mid, int const right, int flag, int flag1)
{
	// flag1 determines if it should return < or >
   // flag determines if it should return comparison by title , author or isbn
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	std::vector<Book> leftArray;
	std::vector<Book> rightArray;
	


	for (int i = 0; i < subArrayOne; i++)
		leftArray.push_back (array[left + i]);
	for (int j = 0; j < subArrayTwo; j++)
		rightArray.push_back( array[mid + 1 + j]);

	int indexOfSubArrayOne = 0,
		indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;


	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne].smaller_by(rightArray[indexOfSubArrayTwo], flag, flag1)) {
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


void mergeSort(std::vector<Book>& array, int const begin, int const end, int flag, int flag1)
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
	a.list = this->list;
	//quickSort(a.list, 0, a.size() - 1, flag, flag1);
	mergeSort(a.list, 0, a.size() - 1, flag, flag1);
	
	//std::sort(a.list.begin(), a.list.end(), [&](const Book& a, const Book& b) {return a.smaller_by(b, flag, flag1); });
	return a;
}
BookList::BookList()
{
	
}
BookList::BookList(const BookList& other)
{
	try
	{
		this->list = other.list;
	}
	catch (const std::exception& e)
	{
		throw;
	}
}

void BookList::push(const Book & b)
{
	list.push_back(b);
}
void BookList::pop()
{
	list.pop_back();
}
Book& BookList ::operator[](const unsigned int& i)
{
	return list[i];
}

int BookList::elem( const Book& b)
{
	
	int s = list.size();
	for (int i = 0; i < s; i++)
	{
		if (list[i].equal (b)) return i;
		
	}
	return -1;
}
void BookList::remove( const Book& b)
{
	int ind = elem(b);
	if (ind  != -1)
	{
		int s = list.size();
		for (int i = 0; i < s-1; i++)
		{
			std::swap(list[i], list[i+1]);
		}
		list.pop_back();
	}
}
void BookList::reserve(int size1)
{
	list.reserve(size1);
}
int BookList::size()const
{
	return this->list.size();
}
BookList::~BookList()
{
	
}
void BookList::print()const
{

	int s = list.size();
	for (int i = 0; i < s; i++)
	{
	 list[i].Print();
		std::cout << "\n";
	}
}
BookList & BookList ::operator =(const BookList& other)
{
	if (this != &other)
	{
		this->list = other.list;
		
	}
	return *this;
}
