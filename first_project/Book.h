#pragma once
#include"String.h"
# include "Isbn.h"
# include <iostream>
struct Book {
	Book() = default;
	Book(const String&, const String&, const String&, const String&, const double&, const Isbn&);
	Book(const Book& );
	Book& operator =(const Book&);
	String get_author()const;
	String get_title()const;
	String get_source()const;
	String get_description()const;
	double get_rating ()const;
	Isbn  get_isbn()const;
	bool smaller_by (  Book& other, unsigned int , unsigned int )const ;

	void print(const int& flag, const int& cnt)const;
	void Print()const;
	bool operator ==(const Book&);
private:
	String author;
	String title;
	String source;
	String description;
	double rating;
	Isbn isbn;

};
