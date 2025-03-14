#include "MyString.h"
#include <cstring>  // strcpy

// definition of all the functions declared in MyString.h

// default constructor
MyString::MyString(){
    data = new char[1];
    length = 0;
    data[0] = '\0';
}

// parameterized constructor
MyString::MyString(const char *str){
    data = new char[strlen(str) + 1];
    length = strlen(str);
    strcpy(data,str);
}

// copy constructor
MyString::MyString(const MyString &other){
    data = new char[other.length + 1];
    length = other.length;
    strcpy(data,other.data);
}

// destructor
MyString::~MyString(){
    delete[] data;
}

// size 
int MyString::size() const{
    return length;
}

// empty
bool MyString::empty() const{
    return length == 0;
}

const char*MyString::c_str() const{
    return data;
}

std::ostream &operator<<(std::ostream &os,const MyString &str){
    os << str.c_str();
    return os;
}

char MyString::operator[](int index){
    if(index >= length){
        return '\0';
    }
    return data[index];
}

int MyString::find(const MyString &substr) const{
    if(substr.length > length){
        return -1;
    }
    for(int i=0;i<=length-substr.length;i++){
        int j;
        for(j=0;j<substr.length;j++){
            if(data[i+j] != substr.data[j]){
                break;
            }
        }
        if(j == substr.length){
            return i;
        }
    }
    return -1;
}