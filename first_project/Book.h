#pragma once
#include"String.h"
# include "Isbn.h"
# include <iostream>
/// @param compare contains two types that determine if the object should be compared by > or <
enum compare
{
	Greater,
	Smaller,
};
/// @param compare_by contains some of the class private variables , it is used for someof the methods
enum compare_by
{
	TITLE,
	AUTHOR,
	ISBN,
	DESCRIPTION,
};
/// @param  gets what it should be sorted by
enum print_by
{
	LINES,
	SENTENCES,
};
struct Book {
	Book() = default;
	Book(const String&, const String&, const String&, const String&, const double&, const Isbn&);
	Book(const Book& );
	Book& operator =(const Book&);
	const String & get_author()const;
	const String & get_title()const;
	const String & get_source()const;
	const String & get_description()const;
	double get_rating ()const;
	Isbn  get_isbn()const;
	bool smaller_by (  Book& other, compare & , compare_by &  )const ;
	void output(print_by &, const int& cnt)const;
	void print()const;
	bool operator ==(const Book&);
private:
	String author;
	String title;
	String source;
	String description;
	double rating;
	Isbn isbn;

};
