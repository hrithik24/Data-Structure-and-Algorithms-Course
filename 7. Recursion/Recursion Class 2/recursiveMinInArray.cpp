#include<iostream>
#include<limits.h>
using namespace std;
void findMin(int arr[],int size,int index,int &minNo){
    // base case
    if(index >= size ){
        return;
    }

    // processing
   minNo = min(minNo, arr[index]);
    
    // recursive call
    findMin(arr,size,index+1,minNo);
}
int main(){
    int arr[] = {20,56,1,90,34};
    int size = 5;
    int index = 0;
    int minNo = INT_MAX;
    findMin(arr,size,index,minNo);
    cout << "Minimum Number of an Array: " << minNo << endl;

}