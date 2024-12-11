#include<iostream>
using namespace std;
int findPivotElement(int arr[], int n){
    int start = 0;
    int end = n - 1;
    int mid;
    while(start <= end){
        mid = start + (end - start) / 2;
        // corner case
        if(start == end){
            return start;
        }

        // Separetdly handle cases
        if(arr[mid] > arr[mid+1]){
            return mid;
        }

        else if(arr[mid-1] > arr[mid]){
            return mid-1;
        }

        // condition for b part
        else if(arr[start] > arr[mid]){
            end = mid - 1;
        }
        
        // condtion for a part
        else{
            start = mid + 1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {12,14,16,2,4,6,8,10};
    int n = 9;
    cout << "Pivot Element: " << findPivotElement(arr,n);
}