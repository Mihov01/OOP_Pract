#include "Store.h"


// a function that converts a long long to a string 
String to_string(long long a)
{
    String b ;
    while (a)
    {
        b += ('0' + a % 10);
        a /= 10;
    }
    String c;
    int size = b.size();
    int ind = size - 1;
    for (int i = 0; i < size; i++)
    {
        c += b[ind--];
    }

    return c;
}
// int the constructor the user should set the password for the authorised commands 
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
// if the password is correct the new book is added to the library 
void Store::add()
{
    try {
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
            while (true)
            {
                a = getchar();
                if (a == '^Z') break;

                descr.push_back(a);
            }

            std::cout << "\n Source:" << sor << "\n";
            std::cout << "Please enter the rating of the book  : \n";
            double rating;
            std::cin >> rating;
            std::cout << "Please enter the ISBN of the book : \n";
            long long isbn;
            std::cin >> isbn;
            Book b(aut, tit, sor, descr, rating, isbn);

            books.push_back(b);
            std::cin.clear();
            return;
        }
        else
        {
            std::cout << "Incorrect password\n";
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what();
        throw e;
    }
}

// removes if found a book from the library , by the title of the book time complexity tita(n)
void Store::remove()
{
    try
    {
        if (correct_password())
        {
            std::cout << "Please enter the title of the book you wish to remove: \n";
            String title;
            title.getline();
            Book* b = find(title, 0);
            if (b != nullptr)
                remove(*b);
            delete b;
        }
        else
        {
            std::cout << "Incorrect password\n";
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what();
        throw e;
    }
}
// if tthe book exists in the library then the index of the book is return otherwise it returns -1  time complexity tita(n)
int Store::elem(const Book& b)
{

   
    int s = books.size();
    for (int i = 0; i < s; i++)
    {
        if (books[i].equal(b)) return i;

    }
    return -1;
}
// time complexity tita (n)
void Store::remove(const Book& b)
{
    try
    {
        int ind = elem(b);
        if (ind != -1)
        {
            int s = books.size();
            for (int i = 0; i < s - 1; i++)
            {
                std::swap(books[i], books[i + 1]);
            }
            books.pop_back();
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what();
        throw e;
    }
}
// an algoritm that sortes a vector using merge sort time complexity tita(nlogn)
void merge(std::vector<Book>& array, int const left, int const mid, int const right, int flag, int flag1)
{
    // flag1 determines if it should return < or >
   // flag determines if it should return comparison by title , author or isbn
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    std::vector<Book> leftArray;
    std::vector<Book> rightArray;



    for (int i = 0; i < subArrayOne; i++)
        leftArray.push_back(array[left + i]);
    for (int j = 0; j < subArrayTwo; j++)
        rightArray.push_back(array[mid + 1 + j]);

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
// returns the sorted vector 
std::vector<Book> Store::sorted_books(int flag, int flag1)
{

    std::vector<Book> a;
    a = this->books;

    mergeSort(a, 0, a.size() - 1, flag, flag1);

    
    return a;
}
// return a dynamicly allocated book if the book is found .... returns nullptr otherwise 
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
