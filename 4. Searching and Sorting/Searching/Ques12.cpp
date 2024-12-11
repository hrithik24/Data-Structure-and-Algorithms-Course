#include<iostream>
using namespace std;
int occurringElement(int arr[],int n){
    int start = 0;
    int end = n - 1;
    int mid;
    while(start <= end){
        mid = start + (end - start) / 2;

        // single element case
        if(start == end){
            return start;
        }
        // For Even Index
        if(mid % 2 == 0){
            if(mid + 1 < n && arr[mid] == arr[mid+1]){
                start = mid + 2;
            }
            else{
                end = mid;
            }
        }
        // For Odd Index
       else{
            if(mid - 1 >=0 && arr[mid] == arr[mid - 1]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }
    return -1;
}
int main(){
    int arr[] = {1,1,5,5,2,2,3,3,2,4,4};
    int n = 11;
    int ans = occurringElement(arr,n);
    cout << "Occurring Element: " <<arr[ans];
}