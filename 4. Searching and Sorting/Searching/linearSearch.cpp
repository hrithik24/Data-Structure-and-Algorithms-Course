#include<iostream>
using namespace std;
bool linearSearch(int arr[],int key,int n){
    for(int i=0;i<n;i++){
        if(arr[i] == key){
            return true;
        }
    }
    return false;
}
int main(){
    int arr[10] = {34,90,12,89,100,1,45,231,90,16};
    int key;
    cin >> key;
    bool ans = linearSearch(arr,key,10);
    if(ans == true){
        cout << "Element Found";
    }
    else{
        cout << "Element Not Found";
    }
}