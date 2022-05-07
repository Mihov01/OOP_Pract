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
void merge(BookList array, int const left, int const mid, int const right, int flag, int flag1 )
{
 // flag1 determines if it should return < or >
// flag determines if it should return comparison by title , author or isbn
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    BookList leftArray,
         rightArray;
    leftArray.reserve(subArrayOne);
    rightArray.reserve(subArrayTwo);

   
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0, 
        indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 

   
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne].smaller_by(rightArray[indexOfSubArrayTwo],flag, flag1)) {
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


void mergeSort(BookList array, int const begin, int const end, int flag, int flag1)
{
    if (begin >= end)
        return; 

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid, flag,flag1);
    mergeSort(array, mid + 1, end,flag, flag1);
    merge(array, begin, mid, end,flag, flag1);
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
        std::cout << "Please type description of the book , if you are done, please enter ctr + C : \n";
        char a = ' ';
        String descr;
        while ( a!= EOF)
        {
            a = getchar();
            if (a == '^Z') break;
          
            descr.push_back(a);
        }
        std::cout << "Please enter the source of the book : \n";
        String sor;
        sor.getline();
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
        std::cout << "Please enter the title of teh book you wish to remove: \n";
        String title;
        title.getline();
        Book b = find(title, 0);
        books.remove(b);
    }
    else
    {
        std::cout << "Incorrect password\n";
    }
}

BookList Store::sorted_books(int flag, int flag1)
{
    BookList a = this->books;
    mergeSort(a, 0, a.Size(), flag, flag1);
    return a;
}
Book Store::find(const String& str, const int & flag)
{
    bool found = false;
    int size = books.Size();
    switch (flag)
    {
    case 0 : 
    {
      
        for (int i = 0; i < size; i++)
        {
            if (books[i].get_title() == str)
            {
                return books[i];
            }
        }
        std::cerr << "No such book found\n";
    }break;
    case 1:
    {

        for (int i = 0; i < size; i++)
        {
            if (books[i].get_author() == str)
            {
                return books[i];
            }
        }
    }break;
    case 2:
    {

        for (int i = 0; i < size; i++)
        {
            if (to_string(books[i].get_isbn()) == str)
            {
                return books[i];
            }
        }
    }break;
    case 3:
    {

        for (int i = 0; i < size; i++)
        {
            if (books[i].get_description().matching_substr(str))
            {
                return books[i];
            }
        }
    }break;
    }
}
