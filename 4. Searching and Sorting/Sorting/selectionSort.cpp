#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
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
    selectionSort(arr);
    print(arr);
}