#pragma once
#include <cstddef>
# include <iostream>
class String {
    char* str = nullptr;
    std::size_t len = 0;

    void copy(const String&);
    
public:
    String();
    //rule of 3
    String(const String&);
    String& operator=(const String&);
    ~String();

    String(const char*);

    bool operator==(const String&) const;
    bool operator!=(const String&) const;

    char& at(std::size_t pos);
    const char& at(std::size_t pos) const;

    char& operator[](std::size_t pos);
    const char& operator[](std::size_t pos) const;

    char& front();
    const char& front() const;
    char& back();
    const char& back() const;

    void push_back(char c);
    void pop_back();

    String& operator+=(char c);
    String& operator+=(const String& rhs);
    
    String operator+(char c) const;
    String operator+(const String& rhs) const;

    const char* c_str() const;

    bool operator<(const String& rhs) const;
    bool matching_substr(const String& str);
    void clear();
    std::size_t size() const;
    bool empty() const;
    void print();
    void getline();
    friend std::ostream& operator << (std:: ostream& out, const String& str);

};