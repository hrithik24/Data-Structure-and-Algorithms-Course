#include<iostream>
using namespace std;
int binarySearch(int arr[],int start, int end,int target){
    // base case
    if(start > end){
        return -1;
    }

    // processing
    int mid = start + (end - start) / 2;
    if(arr[mid] == target){
        return mid;
    }

    if(arr[mid] < target){
        // right me jao
        return binarySearch(arr,mid+1,end,target);
    }
    else{
        // left me jao
        return binarySearch(arr,start,mid-1,target);
    }


}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int start = 0;
    int end = 10;
    int target = 8;
    int foundIndex = binarySearch(arr,start,end,target);

    if(foundIndex != -1){
        cout << "Target found at index: " << foundIndex << endl;
    }
    else{
        cout << "Target does not found." << endl;
    }
    
}