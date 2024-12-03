#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> v){
    cout << "Printing the vector: " << endl;
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;

}

void print1(vector<char> ch){
    cout << "Printing using for-each loop: " << endl;
    for(auto it:ch){
        cout << it << " ";
    }
    cout << endl;
}
int main(){
    vector<int> v;

    // insert
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    print(v);

    // delete
    v.pop_back();
    print(v);

    // user input vector
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int d;
        cin >> d;
        v.push_back(d);
    }
    print(v);

   // print the element at this position in vector
   cout << v.at(4) << endl;

   // to clear the vector
   v.clear();

   // vector initialization
   vector<int> arr; // initializating an vector with no value and 0 size
   vector<int> arr1(5,10); // initializating an vector with specific value and n size
   print(arr1);
   vector<int> arr2 = {1,2,3,4,5}; // initializating an vector with specific given values
   print(arr2);
   vector<int>arr3{10,20,30,40,50}; // initializating an vector with specific given values
   print(arr3);

   // how to copy vector
   vector<int> ans = {100,101,102,103};
   vector<int> ans1(ans);
   print(ans1);

   // Character type of vector
   vector<char> ch;
   ch.push_back('a');
   ch.push_back('b');
   ch.push_back('c');

   // first and last element of vector
   cout << "First Element: " << ch[0] << endl;
   cout << "Last Element: " << ch[ch.size()-1] << endl;
   // In-build function to get the first and last element
   cout << "First element: " << ch.front() << endl;
   cout << "Last element: " << ch.back() << endl;

   // printing using for-each loop
   print1(ch);

}
