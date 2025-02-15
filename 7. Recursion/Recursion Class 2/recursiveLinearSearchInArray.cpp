#include<iostream>
using namespace std;
bool linearSearch(int arr[],int size,int index,int target){
    // base case
    if(index >= size){
        return false;
    }
    if(arr[index] == target){
        return true;
    }

    // recursive call
    bool aageKaAns = linearSearch(arr,size,index+1,target);
    return aageKaAns;
}
int findElement(int arr[],int size,int index,int target){
    // base case
    if(index >= size){
        return -1;
    }
    if(arr[index] == target){
        return index;
    }

    // recursive call
    findElement(arr,size,index+1,target);
}
// find occurrence of target
void findElementOccurrence(int arr[],int size,int index,int target){
    // base case
    if(index >= size){
        return;
    }
    if(arr[index] == target){
        cout << index << " ";
    }

    // recursive call
    findElementOccurrence(arr,size,index+1,target);
}
int main(){
    int arr[] = {10,50,30,40,50};
    int size = 5;
    int index = 0;
    int target = 50;
    // cout << linearSearch(arr,size,index,target);
    findElementOccurrence(arr,size,index,target);
}