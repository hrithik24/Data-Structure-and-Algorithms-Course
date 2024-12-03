#include<iostream>
using namespace std;
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
}
bool linearSearch(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i] == target){
            return true;
        }
    }
    return false;
}

int main(){
    int arr[5] = {1,2,3,4,5};
    printArray(arr,5);
    cout << endl;
    bool ans = linearSearch(arr,5,13);
    if(ans == 1){
        cout << "Target Found";
    }
    else{
        cout << "Target Not Found";
    }
}