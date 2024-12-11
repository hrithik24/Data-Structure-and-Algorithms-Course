#include<iostream>
using namespace std;
int firstOccurence(int arr[], int n, int key){
    int start = 0;
    int end = n - 1;
    int mid,ans = -1;
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid] == key){
            ans = mid;
            end = mid - 1;
        }
        else if(key > arr[mid]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}
int main(){
    int arr[] = {10,20,30,30,30,30,40,50,60};
    cout << "Index: " << firstOccurence(arr,9,30);

}