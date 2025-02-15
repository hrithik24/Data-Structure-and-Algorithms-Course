#include<iostream>
using namespace std;
void change(int *p){
    *p = (*p) * -1;
}
int main(){
    // int a = 5;
    // cout << "Value of a: " << a << endl;
    // cout << "Address of a: " << &a << endl;

    // // pointer creation
    // int* ptr = &a;
    // // value stored at address stored in ptr
    // cout << "Value stored at address stored in ptr: " << *ptr << endl;
    // cout << "Value of ptr: " << ptr << endl;
    // cout << "Address of ptr: " << &ptr << endl;

    // // Pointers examples 1
    // int b = 100;
    // int* ptr1 = &b;
    // cout << "b: " << b << endl;
    // cout << "&b: " << &b << endl;
    // // cout << "*b: " << *b << endl;
    // cout << "ptr1: " << ptr1 << endl;
    // cout << "*ptr1: " << *ptr1 << endl;
    // cout << "&ptr1: " << &ptr1 << endl; 
    // cout << "(*ptr1)+1: " << (*ptr1)+1 << endl;
    // cout << "++(*ptr1): " << ++(*ptr1) << endl;
    // cout << "*ptr1 = *ptr1/2: " << float(*ptr1)/2 << endl;
    // cout << "*ptr1 = *ptr1 - 2: " << *ptr1 - 2 << endl;

    // // Pointer with Arrays
    // int arr[5] = {10,20,30,40,50};
    // cout << "arr: " << arr << endl;
    // cout << "&arr: " << &arr << endl;
    // cout << "arr[0]: " << arr[0] << endl;
    // cout << "&arr[0]: " << &arr[0] << endl;
    // cout << "*arr: " << *arr << endl;
    // cout << "*arr+1: " << *arr+1 << endl;
    // cout << "*(arr)+1: " << *(arr)+1 << endl;
    // cout << "*(arr+1): " << *(arr+1) << endl;
    // cout << "*(arr+2): " << *(arr+2) << endl;
    // cout << "*(arr+3): " << *(arr+3) << endl;

    // // Pointer with Character Arrays
    // char ch[50] = "love";
    // char* cptr = ch;
    // cout << "ch: " << ch << endl;
    // cout << "&ch: " << &ch << endl;
    // cout << "ch[0]: " << ch[0] << endl; 
    // cout << "&cptr: " << &cptr << endl;
    // cout << "*cptr: " << *cptr << endl;
    // cout << "cptr: " << cptr << endl;

    // cout << sizeof(ptr) << endl;
    // cout << sizeof(ptr1) << endl;
    // cout << sizeof(cptr) << endl; 
    // char b[] = "xyz";
    // char* c = &b[0];
    // cout << c; 
    
    int a = 10;
    change(&a);
    cout << a;
}   