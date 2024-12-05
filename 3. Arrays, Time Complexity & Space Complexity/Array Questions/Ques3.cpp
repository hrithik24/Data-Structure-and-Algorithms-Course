#include<iostream>
using namespace std;
void countZeroOnes(int arr[],int size){
    int zeros = 0;
    int ones = 0;
    for(int i=0;i<10;i++){
        if(arr[i] == 0){
            zeros++;
        }
        if(arr[i] == 1){
            ones++;
        }
    }
    cout << "Total Number of Zeros: " << zeros << endl;
    cout << "Total Number of Ones: " << ones << endl;
}
int main(){
    int arr[10] = {0,1,0,0,0,1,1,0,1,0};
    int size = 10;
    countZeroOnes(arr,10);
}