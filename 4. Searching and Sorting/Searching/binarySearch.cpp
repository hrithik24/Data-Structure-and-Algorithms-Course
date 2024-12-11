#include<iostream>
using namespace std;
int binarySearch(int arr[],int key,int n){
    int start = 0;
    int end = n-1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(arr[mid] == key){
            return mid;
        }
        else if(key > arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
    
}
int main(){
    int arr[10] = {1,9,12,34,67,78,89,100,102,450};
    int key;
    cin >> key;
    int ans = binarySearch(arr,key,10);
    cout << ans;
}