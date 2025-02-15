#include<iostream>
#include<limits.h>
using namespace std;
void doubleArray(int arr[],int size,int index){
    // base case
    if(index >= size ){
        return;
    }

    // processing
    arr[index] = arr[index] + arr[index];
    
    // recursive call
    doubleArray(arr,size,index+1);
}
int main(){
    int arr[] = {10,20,30,40,50};
    int size = 5;
    int index = 0;
    doubleArray(arr,size,index);
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }

}