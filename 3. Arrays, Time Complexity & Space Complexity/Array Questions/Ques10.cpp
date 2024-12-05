#include<iostream>
using namespace std;
void sortZeroOnes(int arr[],int size){
    int zeroCount = 0;
    int oneCount = 0;
    for(int i=0;i<size;i++){
        if(arr[i] == 0)
           zeroCount++;
        if(arr[i] == 1)
           oneCount++;
    }

    int i;
    for(i=0;i<zeroCount;i++){
        arr[i] = 0;
    }

    for(int j=i;j<size;j++){
        arr[j] = 1;
    }

    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
}
int main(){
    int arr[] = {0,1,0,1,1,0,0,0,0};
    int size = 9;
    sortZeroOnes(arr,size);  
}