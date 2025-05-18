#include<iostream>
#include<deque>
using namespace std;
void firstNegativeInteger(int *arr,int n,int k){
    deque<int>d;

    // process first k elements -> first window
    for(int index=0;index<k;index++){
        int element = arr[index];
        if(element < 0){
            d.push_back(index);
        }
    }

    // process remaining windows -> removal and addition
    for(int index=k;index<n;index++){
        if(d.empty()){
            cout << "0" << endl;
        }
        else{
            cout << arr[d.front()] << " ";
        }

        // removal -> jo bhe index out of range h, usko queue me se remove kardo
        if(index - d.front() >= k){
            d.pop_front();
        }
        // addition
        if(arr[index] < 0){
            d.push_back(index);
        }
    }

    // last window ka ans print kardo
    if(d.empty()){
        cout << "0" << endl;
    }
    else{
        cout << arr[d.front()] << " "; 
    }
}
int main(){
    int arr[] = {2,-5,4,-1,-2,0,5};
    int n = 7;
    int k = 3;
     
    firstNegativeInteger(arr,n,k);

}