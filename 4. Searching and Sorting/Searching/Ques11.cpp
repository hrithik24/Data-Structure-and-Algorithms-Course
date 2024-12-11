#include<iostream>
using namespace std;
int nearlySortedArray(int arr[],int n,int target){
    int start = 0;
    int end = n - 1;
    int mid;
    while(start <= end){
        mid = start + (end - start) / 2;
        if(mid - 1 > 0 && arr[mid - 1] == target){
            return mid - 1;
        }
        if(arr[mid] == target){
            return mid;
        }
        if(mid + 1 < n && arr[mid + 1] == target){
            return mid + 1;
        }
        if(arr[mid] < target){
            start = mid + 2;
        }
        else{
            end = mid - 2;
        }
    }
    return -1;
}
int main(){
    int arr[] = {20,10,30,50,40,70,60};
    int n = 7;
    int target = 90;
    int ans = nearlySortedArray(arr,n,target);
    if(ans == -1){
        cout << "Element Not Found";
    }
    else{
        cout << "Element Found at Index: " << ans;
    }

}