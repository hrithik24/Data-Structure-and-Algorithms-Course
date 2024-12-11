#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// printing vector
void print(vector<int>& v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout <<  endl;
}

// Custom Comparater
bool myComp(int& a, int& b){
    return a > b; // decreasing order
    // return a < b; // ascending order
}

// printing vector of vector
void printvv(vector<vector<int>>& v){
    for(int i=0;i<v.size();i++){
        vector<int>& temp = v[i];
        int a = temp[0];
        int b = temp[1];
        cout << a << " " << b << endl;
    }
    cout << endl;
}

// Custom Comparator for sorting according to 1st index of vector
bool myCompFor1stIndex(vector<int>& a, vector<int>& b){
    return a[1]  < b[1]; // ascending order
    // return a[1] > b[1]; // descending order
}

int main(){
    vector<int> v = {34,12,90,123,7,45};
    cout << "Befor Sorting: ";
    print(v);

    // increasing order sorting
    cout << "Ascending Order Sorting: ";
    sort(v.begin(),v.end());
    print(v);

    // decreasing order sorting
    cout << "Descending Order Sorting using Custom Comparator: ";
    sort(v.begin(),v.end(),myComp);
    print(v);

    vector<vector<int>> v1 = {{0,11},{1,55},{2,9},{0,99},{3,23}};
    cout << "Printing vector of vector: " << endl;
    printvv(v1);

    // using custom comparator for sorting in ascending order according to 1 index element
    cout << "Sorted in ascending order according to 1st index of vector: " << endl;
    sort(v1.begin(),v1.end(),myCompFor1stIndex);
    printvv(v1);
}