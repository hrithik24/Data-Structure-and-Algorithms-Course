#include<iostream>
using namespace std;
int main(){
    int arr[5];
    for(int i=0;i<5;i++){
        cin >> arr[i];
    }

    int target;
    bool found = 0;
    cout << "Enter the element to search: ";
    cin >> target;

    for(int i=0;i<5;i++){
        if(arr[i] == target){
            found = 1;
            break;
        }
    }

    if(found == 1){
        cout << "Target found";
    }
    else{
        cout << "Not Found";
    }
}