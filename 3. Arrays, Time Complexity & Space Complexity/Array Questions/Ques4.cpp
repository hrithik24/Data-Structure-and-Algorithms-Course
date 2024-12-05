#include<iostream>
#include<limits.h>
using namespace std;
int minNumber(int arr[],int size){
    int minNo = INT16_MAX;
    for(int i=0;i<10;i++){
        if(arr[i] < minNo){
            minNo = arr[i];
        }
    }
    return minNo;
}
int main(){
    int arr[10] = {20,12,90,13,8,100,123,4,83,1000};
    int size = 10;
    int ans = minNumber(arr,10);
    cout << "Minimum Number: " << ans;
}