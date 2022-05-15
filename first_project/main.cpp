# include <iostream>
# include<fstream>
# include "Store.h"
# include "Book.h"
# include <conio.h>

/*! \mainpage Introduction to my Library project 
 *\section github https://github.com/Mihov01
 * \section intro_sec Used data structures
 *
 * The two data structures i have used for this project are vector and string the string is sutable, because the members of the Book class are mostly the names of the book , author etc...
 * I have used the vector because like a real library you never know how big it is going to be and the time complexity of adding an element in a vector is amortised tita(1)
 *
 * \section Idea 
 * So basically tthe idea when i was making this project was to simulate a real library.
 *
 * \subsection : Improving the project
 * 
 * In the future I would like to add annother categorization to the books - genre 
 and i would like to make a database of kind for multiple libraries ;
 *
 * etc...
 */
const String info = "The commands that the library supports are :\n sort - Sorts the books by given criteriia,\n find - Finds a book by a given criteria\n add - Adds a book (autorised access needed)\n remove -Removes a book (autorised access needed)\n print - Prints the content of a book\n exit - Exits the program \n info - prints info about the commands.\n";
enum Commands
{
	Sort,
	Find,
	Add,
	Remove,
	Print,
	Exit,
	Info,
	Error

};
//! converts a string to an enum type
Commands transform(const String& str)
{
	if (str == "sort")
	{
		return Sort;
	}
	else if (str == "find")
	{
		return Find;
	}
	else if (str == "add")
	{
		return Add;
	}
	else if (str == "remove")
	{
		return Remove;
	}
	else if (str == "print")
	{
		return Print;
	}
	else if (str == "info")
	{
		return Info;
	}
	else if (str == "exit")
	{
		return Exit;
	}
	else {
		return Error;
	}
}
//! prints the contents of a vector 
void print(std::vector<Book>& a)
{
	int size = a.size();
	for (int i = 0; i < size; i++)
	{
		a[i].print();
		std::cout << "\n";
	}
	std::cout << "\n";
}
bool process(Store & a ,Commands comm)
{
	try {
		switch (comm)
		{
		case Sort:
		{
			compare_by flag1;
			compare flag2;
			std::cout << "Do you wish to sort by descending or ascending order ?\n";
			String c1;
			c1.getline();
			if (c1 == "descending")
			{
				flag2 = Greater;
			}
			else if (c1 == "ascending")
			{
				flag2 = Smaller;
			}
			else
			{
				std::cerr << "Wrong input\n";
				return -1;
			}
			std::cout << "By which criteria do you wih to sort the books? :  \n Author, Title or Isbn?\n";
			String c;
			c.getline();
			if (c == "Title")
			{
				flag1 = TITLE;
			}
			else if (c == "Author")
			{
				flag1 = AUTHOR;
			}
			else if (c == "Isbn")
			{
				flag1 = ISBN;
			}
			else
			{
				std::cerr << "Wrong input\n";
				return -1;
			}
			std::vector<Book> temp;

			temp = a.sorted_books(flag2, flag1);
			print(temp);
			return 1;
		}; break;
		case Find:
		{
			compare_by flag;
			std::cout << "By witch criteria do you wish to search?\n Author , Title , Description , Isbn?\n";
			String c;
			String v;
			c.getline();
			if (c == "Title")
			{ flag = TITLE; 
			std::cout << "Please enter the title of the book:\n";
			v.getline();
			}
			else if (c == "Author")
			{
				flag = AUTHOR;
				std::cout << "Please enter the author of the book :\n";
				v.getline();
			}
			else if (c == "Isbn") {
				flag = ISBN;
				std::cout << "Please enter the author of the book (it should be in the format num1  num2 num3 num4 ,where num[i] is a part of the ISBN)  :\n";
				v.getline();
			}
			else if (c == "Description") {
				flag = DESCRIPTION;
				std::cout << "Please enter the part of the description u search for in the book :\n";
				v.getline();
			}
			else {
				std::cerr << "Wrong input\n";
				return -1;
			}
			
			
			Book* f = a.find(v, flag);
			if (f != nullptr)
			{
				f->print();
				
			}
			else {
				std::cerr << "No such book found\n";
			}
			return 1;
		}; break;
		case Add:
		{
			a.add();
			std::cin.ignore(10000, '\n');
			return 1;
		}; break;
		case Remove:
		{
			a.remove();
			std::cin.ignore(10000, '\n');
			return 1;
		}; break;
		case Print:
		{
			String title;
			std::cout << "Pease enter the title of the book you wish to read\n";
			title.getline();
			print_by flag;
			String what;
			std::cout << "Do you wish to read a sertain number of lines or of sentences? ( please tipe lines or sentences): \n";
			what.getline();
			if (what == "lines")
				flag = LINES;
			else if (what == "sentences")
				flag = SENTENCES;
			else {
				std::cerr << "Wrong input\n";
				return -1;
			}
			std::cout << "Please enter the count\n";
			int cnt;
			std::cin >> cnt;
			compare_by cmp = TITLE;
			Book* f = a.find(title, cmp);
			if (f != nullptr)
			{
				f->output(flag, cnt);
			
			}
			else
			{
				std::cerr << "No such book\n";
			}
			std::cin.ignore(10000, '\n');
			return 1;
		}; break;
		case Info:
		{
			std::cout << info;
			return 1;
		}; break;
		case  Error:
		{std::cerr << "Invalid command\n"; return 1; break; }break;
		case Exit:
		{
			return 0;
		}; break;
		}
	}
	catch (const std::exception& e)
	{
		throw e;
	}
}

int main()try
{
	std::cout << "Please set password : \n";
	char b = _getch();
	std::cout << "*";
	String password;
	password.push_back(b);
	while (b != '\r')
	{
		b = _getch();
		std::cout << "*";
		password.push_back(b);
	}
	Store a(password);	
	String str;
	std::cout <<"\n" << info << "\n";
	while (true)
	{		
		str.clear();
		
		std::cout << "Please enter a command\n";

		str.getline();

		Commands comm = transform(str);
		if (!process(a, comm)) break;	
	}
	
}
catch (const std::exception& e)
{
	std::cerr << e.what();
	return -1;
}