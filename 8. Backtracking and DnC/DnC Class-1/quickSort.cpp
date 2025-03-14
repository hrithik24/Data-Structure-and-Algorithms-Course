#include<iostream>
using namespace std;
void quickSort(int arr[],int start,int end){
    // base case
    if(start >= end){
        return;
    }

    // taking last element as pivot
    int pivot = end;
    int i = start - 1;
    int j = start;
    while(j < pivot){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }

    // placing pivot element at his correct position
    i++;
    swap(arr[i],arr[pivot]);
    // After replacing pivot element at correct postion doing the recursive call for left and right part of sub-]]array
    quickSort(arr,start,i-1);
    quickSort(arr,i+1,end);
}
int main(){
    int arr[] = {2,1,9,7,4,6};
    int size = 6;
    int start = 0;
    int end = size - 1;

    cout << "Before quick sort: " << endl;
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr,start,end);

    cout << "After quick sort: " << endl;
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}