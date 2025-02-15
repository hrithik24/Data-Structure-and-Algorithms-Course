#include<iostream>
using namespace std;
bool arraySorted(int arr[],int size,int index){
    // base case
    if(index >= size){
        return true;
    }

    // processing
    if(arr[index] > arr[index-1]){
        // recursive call
        bool ans = arraySorted(arr,size,index+1);
        return ans;
    }
    else{
        return false;
    }

    
}
int main(){
    int arr[] = {10,20,30,40,50,60};
    int size = 6;
    int index = 1;

    bool sorted = arraySorted(arr,size,index);
    if(sorted){
        cout << "Array is sorted" << endl;
    }
    else{
        cout << "Array is not sorted" << endl;
    }
}