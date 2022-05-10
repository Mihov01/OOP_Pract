# include "Book.h"
# include <fstream>
//! checks if a symbol is a mark ,  ending a sentence 
bool mark(const char& a)
{
	return a == '.' || a == '!' || a == '?';
}
//!copy constructor
Book::Book(const Book& other)
{

	this->author = other.author;
	this->title = other.title;
	this->source = other.source;
	this->description = other.description;
	this->rating = other.rating;
	this->isbn = other.isbn;
}

Book ::Book
   (const String& author, 
	const String& title ,
	const String& source , 
	const String& description  , 
	const double&rating ,
	const Isbn& isbn)
	{
	this->author = author;
	this->title = title;
	this->source = source;
	this->description = description;
	this->rating = rating;
	this->isbn = isbn;
	}
String Book::get_author()const
{
	return this->author;
}
String Book::get_title()const
{
	return this->title;
}
String Book::get_description()const
{
	return this->description;
}
String Book::get_source() const
{
	return this->source;
}
double Book::get_rating() const
{
	return this->rating;
}
 Isbn Book::get_isbn()const
{
	return this->isbn;
}
//! checs if a book is smaller / bigger than this book given a criteria 
bool Book::smaller_by(  Book & other, unsigned int flag = 0, unsigned int flag1 = 0)const
{
//@param flag1 determines if it should return < or >
//@param flag determines if it should return comparison by title , author or isbn
	switch (flag1)
	{
	case 0: {
		switch (flag)
		{
		
		case 0: return title < other.title; break;
		case 1: return author < other.author; break;
		case 2: return    other.isbn<this->isbn; break;
		}
	} break;
	case 1:
	{
		switch (flag)
		{
		case 0: return !(title < other.title); break;
		case 1: return !(author < other.author); break;
		case 2: return  other.isbn > isbn; break;
		}
	}break;
	}
}
//! operator == checks if to books are equal
Book& Book ::operator=(const Book& other)
{
	if (this != &other)
	{
		this->author = other.author;
		this->description = other.description;
		this->title = other.title;
		this->rating = other.rating;
		this->isbn = other.isbn;
		this->source = other.source;
	}
	return *this;

}
 bool Book ::operator==( const Book& b)
{
	 //!!operator ==
	return (b.title == title &&
		b.author == author &&
		b.description == description &&
		b.source == source &&
		b.rating == rating &&
		 isbn== b.isbn );

}
 //! prints a given number of lines or sentences from the source 
   /// @param cnt the number of lines or sentences
 ///@param flag determines if the cnt is about lines or sentences
 void Book::print(const int& flag, const int& cnt) const
 
 {
	
	 //! if flag is 0 the program reads cnt lines else it reads cnt sentences
	 switch (flag)
	 {
	 case 0:
	 {
	
		 std::string a;
		 std::ifstream b;
		 b.open(this->source.c_str());
		 char c = ' ';
		 int cnt_n = 0;
		 while (cnt_n != cnt && !b.eof())
		 {
			 c = b.get();

			 if (c == '\n') cnt_n++;
			 a.push_back(c);

		 }
		 b.close();
		 std::cout << a;
	 }break;
	 case 1:
	 {
		 std::string a;
		 std::ifstream b;
		 b.open(this->source.c_str());
		 char c = ' ';
		 int cnt_n = 0;
		 while (cnt_n != 15 && !b.eof())
		 {
			 c = b.get();

			 if (mark(c)) cnt_n++;
			 a.push_back(c);

		 }
		 b.close();
		 std::cout << a;
	 }
	 }
 }


 void Book::Print()const 
 {
	 //! prints the basic informaton about the book
	 std::cout <<"The title of the book is : " << title << "\nThe author of the book is" << author << "\nThe description of the book is :  " << description << "The source of the book is : " << source << "\n The raiting of the book is  " << rating << "\n The isbn of the book is : " << isbn << '\n';
 }