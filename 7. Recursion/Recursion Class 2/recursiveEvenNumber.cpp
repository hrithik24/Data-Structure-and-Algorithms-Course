#include<iostream>
#include<vector>
using namespace std;
void even(int arr[],int size,int index,vector<int> &ans){
    // base case
    if(index >= size){
        return;
    }

    // processing
    if(arr[index] % 2 ==0){
        ans.push_back(arr[index]);
    }

    // recursive call
    even(arr,size,index+1,ans);
}
int main(){
    int arr[] = {23,12,90,29,11,93,34,87,3,131};
    int size = 10;
    int index = 0;
    vector<int> ans;
    even(arr,size,index,ans);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
}