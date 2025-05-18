#include<iostream>
#include<queue>
using namespace std;
int getKthSmallestElement(int arr[],int n,int k){
    priority_queue<int> pq;
    // first k element ko process karo
    for(int i=0;i<k;i++){
        int element = arr[i];
        pq.push(element);
    }

    // remaining element ko tabhi insert karenge jab vo root se chote honge
    for(int i=k;i<n;i++){
        int element = arr[i];
        if(element < pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}
 
int getKthGreatestElement(int arr[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    // first k element ko process karo
    for(int i=0;i<k;i++){
        int element = arr[i];
        pq.push(element);
    }

    // remaining element ko tabhi insert karenge jab vo root se chote honge
    for(int i=k;i<n;i++){
        int element = arr[i];
        if(element > pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;

}
int main(){
    int arr[] = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    int n = 9;
    cout << "4rd Smallest number is: " << getKthSmallestElement(arr,n,k) << endl;
    // cout << "6rd Greatest number is: " << getKthGreatestElement(arr,n,k) << endl;

}