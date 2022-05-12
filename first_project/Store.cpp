#include "Store.h"

inline bool number(const char& a)
{
    return a > '0' && a < '9';
}
//! a function that converts a long long to a string 
String remove_spaces(const String & a)
{

    String b ;
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        if (number(a[i]))b.push_back(a[i]);
    }
  

    return b;
}
//! in the constructor the user should set the password for the authorised commands 
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
//! if the password is correct the new book is added to the library 
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
            std::cout << "Please type description of the book , if you are done, please enter enter and after that  ctr + Z : \n";
            char a = ' ';
            String descr;
            while (a!= EOF)
            {
                a = getchar();
                if (a == '^Z') break;

                descr.push_back(a);
            }
            std::cout << "Please enter the rating of the book (the raiting should be between 0 and 10) : \n";
            double rating;
         
          
            std::cin >> rating;
            if (!std::cin) { std::cin.clear(); throw std::runtime_error("bad input\n"); }
            if (rating > 10 || rating < 0)
            {
                throw std::runtime_error("bad input\n");
            }
            std::cout << "Please enter the ISBN of the book : (it should be unique ISBN\n";
            std::cout << "-----------------------------------------------\n";
             Isbn isbn;
            std::cin >> isbn;
            Book* f = this->find(isbn.to_string(), 2);
            if (f == nullptr)
            {
                Book b(aut, tit, sor, descr, rating, isbn);

                books.push_back(b);

                return;
            }
            else {
                std::cerr << "This isbn alfeady exist\n";
            }
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

//! removes if found a book from the library , by the title of the book time complexity tita(n)
void Store::remove()
{
    try
    {
        if (correct_password())
        {
            std::cout << "Please enter the ISBN of the book you wish to remove: \n";
            Isbn isbn;
            std::cin >> isbn;
            Book* b = find(isbn.to_string(), 2);
            if (b != nullptr)
                remove(*b);
           
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
//! if tthe book exists in the library then the index of the book is return otherwise it returns -1  time complexity tita(n)
int Store::elem(const Book& b)
{

   
    int s = books.size();
    for (int i = 0; i < s; i++)
    {
        if (books[i]==b) return i;

    }
    return -1;
}
//! time complexity tita (n)
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
//! an algoritm that sortes a vector using merge sort time complexity tita(nlogn)
void merge(std::vector<Book>& array, int const left, int const mid, int const right, int flag, int flag1)
{
    ///@param flag1 determines if it should return < or >
   ///@param flag determines if it should return comparison by title , author or isbn
    int const lenght_arr1 = mid - left + 1;
    int const lenght_arr2 = right - mid;

    std::vector<Book> leftArray;
    std::vector<Book> rightArray;



    for (int i = 0; i < lenght_arr1; i++)
        leftArray.push_back(array[left + i]);
    for (int j = 0; j < lenght_arr2; j++)
        rightArray.push_back(array[mid + 1 + j]);

    int ind_arr_1 = 0,
        ind_arr_2 = 0;
    int ind_merged = left;


    while (ind_arr_1 < lenght_arr1 && ind_arr_2 < lenght_arr2) {
        if (leftArray[ind_arr_1].smaller_by(rightArray[ind_arr_2], flag, flag1)) {
            array[ind_merged] = leftArray[ind_arr_1];
            ind_arr_1++;
        }
        else {
            array[ind_merged] = rightArray[ind_arr_2];
            ind_arr_2++;
        }
        ind_merged++;
    }

    while (ind_arr_1 < lenght_arr1) {
        array[ind_merged] = leftArray[ind_arr_1];
        ind_arr_1++;
        ind_merged++;
    }

    while (ind_arr_2 < lenght_arr2) {
        array[ind_merged] = rightArray[ind_arr_2];
        ind_arr_2++;
        ind_merged++;
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
 
std::vector<Book> Store::sorted_books(int flag, int flag1)
{
    //! returns the sorted vector
    std::vector<Book> a;
    a = this->books;

    mergeSort(a, 0, a.size() - 1, flag, flag1);

    
    return a;
}
//! return a dynamicly allocated book if the book is found .... returns nullptr otherwise 
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
                return &books[i];
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
                return &books[i];
            }
        }
        return nullptr;
    }break;
    case 2:
    {

        for (int i = 0; i < size; i++)
        {
            if (books[i].get_isbn().to_string() == remove_spaces(str))
            {
                return &books[i];
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
                return &books[i];
            }
        }
        return nullptr;
    }break;
    }
}
