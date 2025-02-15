#include<iostream>
#include<limits.h>
using namespace std;
void findMax(int arr[],int size,int index,int &maxNo){
    // base case
    if(index >= size ){
        return;
    }

    // processing
   maxNo = max(maxNo, arr[index]);
    
    // recursive call
    findMax(arr,size,index+1,maxNo);
}
int main(){
    int arr[] = {20,56,1,90,34};
    int size = 5;
    int index = 0;
    int maxNo = INT_MIN;
    findMax(arr,size,index,maxNo);
    cout << "Maximum Number in an Array: " << maxNo << endl;

}