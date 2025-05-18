#include<iostream>
using namespace std;
void heapify(int *arr,int n,int index){
    int leftIndex = 2*index;
    int rightIndex = 2*index+1;
    int largestKaIndex = index;

    // teno me se max lao
    if(leftIndex <= n && arr[leftIndex] > arr[largestKaIndex]){
        largestKaIndex = leftIndex;
    }
    if(rightIndex <= n && arr[rightIndex] > arr[largestKaIndex]){
        largestKaIndex = rightIndex;
    }

    // after these 2 conditions largestKaIndex will be pointing towards largest element among 3
    if(index != largestKaIndex){
        swap(arr[index],arr[largestKaIndex]);
        // ab recursion sambhal lega
        index = largestKaIndex;
        heapify(arr,n,index);
    }
}

void buildHeap(int arr[],int n){
    for(int index = n/2;index>0;index--){
        heapify(arr,n,index);
    }
}
int main(){
    
}