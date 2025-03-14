#ifndef MYSTRING_H
#define MYSTRING_H

#include<iostream>

class MyString{
    private:
        char *data; // pointer to char array data
        int length; // size of my string

    public:
        // default constructor
        MyString();

        // parameterized constructor
        MyString(const char *str);

        // copy constructor
        MyString(const MyString &other);

        // destructor
        ~MyString();

        int size() const;

        bool empty() const;

        const char *c_str() const;

        // overload insertion operator (<<) for easy output
        friend std::ostream&operator<<(std::ostream&os,const MyString &str);

        // operator overloading
        char operator[](int index);

        // find substring
        int find(const MyString& substr) const;

};

#endif