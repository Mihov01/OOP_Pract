# include <iostream>
# include "MyString.h"
# include "Store.h"
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
bool process(Store & a ,Commands comm)
{
	switch (comm)
	{
	case Sort:
	{
		int flag1, flag2;
		std::cout << "Do you wish to sort by descending or ascending order ?\n";
		String c1;
		c1.getline();
		if (c1 == "descending")
		{
			flag2 = 1;
		}
		else if (c1 == "ascending")
		{
			flag2 = 0;
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
			flag1 = 0;
		}
		else if (c == "Author")
		{
			flag1 = 1;
		}
		else if (c == "Isbn")
		{
			flag1 = 2;
		}
		else
		{
			std::cerr << "Wrong input\n";
			return -1;
		}
		a.sorted_books(flag1, flag2).print();
		return 1;
	}; break;
	case Find:
	{
		int flag;
		std::cout << "By witch criteria do you wish to search?\n Author , Title , Description , Isbn?\n";
		String c;
		c.getline();
		if (c == "Title") flag = 0;
		else if (c == "Author") flag = 1;
		else if (c == "Isbn") flag = 2;
		else if (c == "Description") flag = 3;
		else {
			std::cerr << "Wrong input\n";
			return -1;
		}
		std::cout << "Please enter :\n";
		String v;
		v.getline();
		a.find(v, flag).Print();
		return 1;
	}; break;
	case Add:
	{
		a.add();
		return 1;
	}; break;
	case Remove:
	{
		a.remove();
		return 1;
	}; break;
	case Print:
	{
		String title;
		std::cout << "Pease enter the title of the book you wish to read\n";
		title.getline();
		int flag;
		String what;
		std::cout << "Do you wish to read a sertain number of linesor of sentences? ( please tipe lines or sentences): \n";
		what.getline();
		if (what == "lines")
			flag = 0;
		else if (what == "sentences")
			flag = 1;
		else {
			std::cerr << "Wrong input\n";
			return -1;
		}
		std::cout << "Please enter the count\n";
		int cnt;
		std::cin >> cnt;
		a.find(title, 1).print(flag, cnt);
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

int main()
{
	Store a;
	
	String str;
	std::cout <<"\n" << info << "\n";

	
	while (true)
	{

		
		str.clear();
		std::cout << "Please enter a command\n";

		str.getline();
		std::cout << str << '\n';
		Commands comm = transform(str);
		if (!process(a, comm)) break;
		std::cin.clear();
	}
	

}