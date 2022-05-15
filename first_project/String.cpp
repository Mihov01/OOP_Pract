#include <iostream>
#include <cstring>
#include <cassert>
#include <stdexcept>
#include "String.h"

void String::copy(const String& other) {
    char* tempStr = new char[other.len + 1];
    strcpy_s(tempStr, other.len + 1, other.str);

    delete[] str;
    str = tempStr;
    len = other.len;
}


String::String() {
    str = new char[1];
    len = 0;
    str[0] = '\0';
}
//! copy constructor
String::String(const String& other) {
    copy(other);
}
//! copy operator
String& String::operator=(const String& other) {
    if (this != &other) {
        copy(other);
    }
    return *this;
}
//! destructor
String::~String() {
    delete[] str;
    len = 0;
}
//! copy constructor
String::String(const char* initString) {
    if (initString == nullptr) {
        str = new char[1];
        len = 0;
        str[0] = '\0';
    }
    else {
        std::size_t newLen = std::strlen(initString);

        char* tempStr = new char[newLen + 1];
        strcpy_s(tempStr, newLen + 1, initString);

        str = tempStr;
        len = newLen;
    }
}
//! returns if two strings are equal
bool String::operator==(const String& rhs) const {
    if (len == rhs.len && std::strcmp(str, rhs.str) == 0) {
        return true;
    }
    return false;
}
//! returns if two strings are different
bool String::operator!=(const String& rhs) const {
    return !operator==(rhs);
}
//! returns the char at position i 
char& String::at(std::size_t pos) {
    if (pos >= len || pos < 0) {
        throw std::out_of_range("pos out of range");
    }

    return str[pos];
}
//! returns the char at position i (const version)
const char& String::at(std::size_t pos) const {
    if (pos >= len || pos < 0) {
        throw std::out_of_range("pos out of range");
    }

    return str[pos];
}
//! returns the char at position i 
char& String::operator[](std::size_t pos) {
    assert(pos >= 0 && pos < len);
    return str[pos];
}
//! returns the char at position i (const version)
const char& String::operator[](std::size_t pos) const {
    assert(pos >= 0 && pos < len);
    return str[pos];
}
//! returns the first char of the string
char& String::front() {
    assert(len > 0);
    return str[0];
}
//! returns the first char of the string (const version)
const char& String::front() const {
    assert(len > 0);
    return str[0];
}
// return the last char of the string 
char& String::back() {
    assert(len > 0);
    return str[len - 1];
}
//! returns a constant version the last  char of the string 
const char& String::back() const {
    assert(len > 0);
    return str[len - 1];
}

//! concats a char to the string
void String::push_back(char c) {
    if (c != '\0') {
        std::size_t newLen = len + 1;
        char* newString = new char[newLen + 1];
        for (std::size_t i = 0; i < len; i++) {
            newString[i] = str[i];
        }
        newString[newLen - 1] = c;
        newString[newLen] = '\0';
        
        delete[] str;
        str = newString;
        len = newLen;
    }
}
//! removes the last char of the string
void String::pop_back() {
    assert(len > 0);

    str[len - 1] = '\0';
    --len;
}
//! concats a char to the string
String& String::operator+=(char c) {
    this->push_back(c);
    return *this;
}
//! concats a string(like string1 or something) to the string
String& String::operator+=(const String& rhs) {
    if (rhs.empty()) {
        return *this;
    }
    if (this->empty()) {
        copy(rhs);
        return *this;
    }

    std::size_t newLen = len + rhs.len;
    char* concatString = new char[newLen + 1];
    for (std::size_t i = 0; i < len; i++) {
        concatString[i] = str[i];
    }
    for (std::size_t j = len; j < newLen; j++) {
        concatString[j] = rhs[j - len];
    }
    concatString[newLen] = '\0';

    delete[] str;
    str = concatString;
    len = newLen;
    
    return *this;
}

//! returns a new string with concatinated char to it 
String String::operator+(char c) const {
    if (c != '\0') {
        String newS = *this;
        newS.push_back(c);
        return newS;
    }
    return *this;
}
//! returns a new string with concatinated a string to it 
String String::operator+(const String& rhs) const {
    String newS = *this;
    newS += rhs;
    return newS;
}
//! returns a c style string
const char* String::c_str() const {
    return str;
}

//! checks if string1 is < that string2
bool String::operator<(const String& rhs) const {
    int thisBeforeOther = std::strcmp(str, rhs.str);
    if (thisBeforeOther < 0) {
        return true;
    }
    return false;
}

//! deletes the string 
void String::clear() {
    str[0] = '\0';
    len = 0;
}
//! gets the size in constant time 
std::size_t String::size() const {
    return len;
}
//! checks if the string is empty
bool String::empty() const {
    if (str == nullptr || len == 0 ) {
        return true;
    }
    return false;
}

//! output operator
std::ostream& operator << (std::ostream& out, const String& str)
{
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        out << str[i];
    }
    return out;
}
//! checks if str is in the string 
bool String::matching_substr(const String& str)const
{
        int counter = 0; 
    
        int length = str.size();
        for (int i=0; i <length; i++)
        {
            if (counter == length)
                break;
            if (str[counter] == this->str[i])
            {
                counter++;
            }
            else
            {
                if (counter > 0)
                {
                    i -= counter;
                }
                counter = 0;
            }
        }
        return counter >= length;
    

}
//! gets a line of text from the standart input 
void String::getline()
{
    char a= ' ';
    while (true)
    {
        std::cin.get(a);
        if (a == '\n') break;
        push_back(a);
    }
}