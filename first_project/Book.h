#pragma once
#include"MyString.h"
# include <iostream>
struct Book {
	Book() = default;
	Book(const String&, const String&, const String&, const String&, const double&, const long long&);
	Book& operator =(const Book&);
	String get_author()const;
	String get_title()const;
	String get_source()const;
	String get_description()const;
	double get_rating()const;
	long long get_isbn()const;
	bool smaller_by (const Book& other, unsigned int , unsigned int );
	bool operator == (const Book&);
	void print(const int& flag, const int& cnt)const;
	friend std::ostream& operator << (std::ostream&, const Book& b);
	void Print()const;
private:
	String author;
	String title;
	String source;
	String description;
	double rating;
	long long isbn;

};
