#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void print(vector<int> &v){
    int n = v.size();
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }
    cout << endl;
}
int main(){
    vector<int> arr = {5,204,13,92,1};
    print(arr);
    bubbleSort(arr);
    print(arr);
}