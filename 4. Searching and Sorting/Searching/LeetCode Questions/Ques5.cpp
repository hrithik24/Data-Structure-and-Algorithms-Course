#include<iostream>
#include<vector>
using namespace std;
int peakIndexInMountainArray(vector<int>& arr,int n){
    int start = 0;
    int end = n - 1;
    int mid;
    while(start < end){
        mid = start + (end - start) / 2;
        if(arr[mid] < arr[mid+1]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    return start;
}
int main(){
    vector<int> arr = {10,20,50,40,30};
    int ans = peakIndexInMountainArray(arr,5);
    cout << "Ans: " << ans;
} 
