# include "Book.h"
# include <fstream>
bool mark(const char& a)
{
	return a == '.' || a == '!' || a == '?';
}
Book::Book(const Book& other)
{
	this->author = other.author;
	this->title = other.title;
	this->source = other.source;
	this->description = other.description;
	this->rating = other.rating;
	this->isbn = other.isbn;
}
Book::Book(const Book* other)
{
	this->author = other->author;
	this->title = other->title;
	this->source = other->source;
	this->description = other->description;
	this->rating = other->rating;
	this->isbn = other->isbn;
}
Book ::Book
   (const String& author, 
	const String& title ,
	const String& source , 
	const String& description  , 
	const double&rating ,
	const long long& isbn)
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
long long Book::get_isbn()const
{
	return this->isbn;
}
bool Book::smaller_by( Book & other, unsigned int flag = 0, unsigned int flag1 = 0)
{
// flag1 determines if it should return < or >
// flag determines if it should return comparison by title , author or isbn
	switch (flag1)
	{
	case 0: {
		switch (flag)
		{
			std::cout << other.title;
		/*case 0: return title < other.title; break;
		case 1: return author < other.author; break;
		case 2: return isbn < other.isbn; break;*/
		}
	} break;
	case 1:
	{
		switch (flag)
		{
		case 0: return !(title < other.title); break;
		case 1: return !(author < other.author); break;
		case 2: return isbn > other.isbn; break;
		}
	}break;
	}
}
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
 bool Book ::equal( Book* b)
{
	return (b->title == title &&
		b->author == author &&
		b->description == description &&
		b->source == source &&
		b->rating == rating &&
		b->isbn == isbn);

}
 void Book::print(const int& flag, const int& cnt) const
 {
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

 std::ostream& operator << (std::ostream& out, const Book& bo)
 {
	 out << bo.get_title() << " " << bo.get_author() << " " << bo.get_isbn();
	 return out;
  }
 void Book::Print()const 
 {
	 std::cout << title << " " << author << " " << description << " "  << source << " " << rating << " " << isbn << '\n';
 }