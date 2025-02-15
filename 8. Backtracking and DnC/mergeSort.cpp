#include<iostream>
using namespace std;
void merge(int arr[],int start,int end){
    int mid = (start+end) / 2;

    int lenLeft = mid - start + 1;
    int lenRight = end - mid;

    // create left and right array
    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    // copy values from original array to left array
    int k = start;
    // k-> starting index of left array values in original array
    for(int i=0;i<lenLeft;i++){
        left[i] = arr[k];
        k++;
    }

    // copy values from original array to right array
    k = mid + 1;
    for(int i=0;i<lenRight;i++){
        right[i] = arr[k];
        k++;
    }

    // actual merge logic here
    // left array is already sorted 
    // right array is already sorted
    int leftIndex = 0;
    int rightIndex = 0;
    // yahi pr galti karte h log
    int mainArrayIndex = start;

    while(leftIndex < lenLeft && rightIndex < lenRight){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // left array khatam ho gaya but right array me element abhi bhi bache hai
    while(rightIndex < lenRight){
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    // right array khatam jo gaya but left array me element abhi bhi bache hai
    while(leftIndex < lenLeft){
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }

    // de-allocation of memory 
    delete[] left;
    delete[] right;
}
void mergeSort(int arr[],int start,int end){
    // base case
    if(start > end){
        // invalid array
        return;
    }
    if(start ==  end){
        // single element
        return;
    }

    // break
    int mid = (start + end) / 2;

    // recursive call on left array
    mergeSort(arr,start,mid); 
    // recursive call on right array
    mergeSort(arr,mid+1,end); 

    // merging 2 sorted arrays
    merge(arr,start,end);
}
int main(){
    int arr[] = {2,1,9,7,4,6};
    int size = 6;
    int start = 0;
    int end = size - 1;

    cout << "Before merge sort: " << endl;
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr,start,end);

    cout << "After merge sort: " << endl;
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}