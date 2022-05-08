#include "Store.h"


String to_string(long long a)
{
    String b;
    while (a)
    {
        b += '0' + a % 10;
        a /= 10;
    }
    String c;
    int size = b.size();
    int ind = size - 1;
    for (int i = 0; i < size; i++)
    {
        c[i] = b[ind--];
    }
    return c;
}

Store::Store()
{
  
    std::cout << "Please set password : \n";
    char b = _getch();
    std::cout << "*";
    password.push_back(b);
    while (b != '\r')
    {
        b = _getch();
        std::cout << "*";
        password.push_back(b);
    }
}
void Store::add()
{
	if (correct_password())
	{
       
        std::cout << "Please enter author : \n";
        String aut;
        aut.getline();
        std::cout << "Please enter title : \n";
        String tit;
        tit.getline();
        std::cout << "Please enter the source of the book : \n";

        String sor;
        sor.getline();
        std::cout << "Please type description of the book , if you are done, please enter ctr + C : \n";
        char a = ' ';
        String descr;
        while ( a!= EOF)
        {
            a = getchar();
            if (a == '^Z') break;
          
            descr.push_back(a);
        }
        
        std::cout << "\n Source:" << sor<< "\n";
        std::cout << "Please enter the rating of the book  : \n";
        double rating;
        std::cin >> rating;
        std::cout << "Please enter the ISBN of the book : \n";
        long long isbn;
        std::cin >> isbn;
        Book b (aut, tit, sor, descr, rating, isbn);
       
		books.push(b);
    std:: cin.clear();
        return;
	}
	else
	{
		std::cout << "Incorrect password\n";
	}
}

void Store::remove()
{
    if (correct_password())
    {
        std::cout << "Please enter the title of the book you wish to remove: \n";
        String title;
        title.getline();
        Book *b = find(title, 0);
        if (b != nullptr)
        books.remove(*b);
        delete b;
    }
    else
    {
        std::cout << "Incorrect password\n";
    }
}

BookList Store::sorted_books(int flag, int flag1)
{

    return books.sort(flag, flag1);
}
 Book*  Store::find(const String& str, const int & flag)
{
    bool found = false;
    int size = books.size();
    switch (flag)
    {
    case 0 : 
    {
      
        for (int i = 0; i < size; i++)
        {
            if (books[i].get_title() == str)
            {
                return new Book (books[i]);
            }
        }
        return nullptr;
    }break;
    case 1:
    {

        for (int i = 0; i < size; i++)
        {
            if (books[i].get_author() == str)
            {
                return new Book(books[i]);
            }
        }
        return nullptr;
    }break;
    case 2:
    {

        for (int i = 0; i < size; i++)
        {
            if (to_string(books[i].get_isbn()) == str)
            {
                return new Book(books[i]);
            }
        }
        return nullptr;
    }break;
    case 3:
    {

        for (int i = 0; i < size; i++)
        {
            if (books[i].get_description().matching_substr(str))
            {
                return new Book(books[i]);
            }
        }
        return nullptr;
    }break;
    }
}
