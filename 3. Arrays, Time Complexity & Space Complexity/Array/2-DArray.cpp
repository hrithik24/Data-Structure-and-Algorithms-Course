#include<iostream>
using namespace std;
void printRowWise(int arr[3][4],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printcolWise(int arr[3][4],int row,int col){
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

// searching in 2D array
bool search(int arr[3][4],int row,int col,int key){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j] == key){
                return true;
            }
        }
    }
    return false;
}

// Maximum number in 2D Array
int maxNum(int arr[3][4],int row,int col){
    int max = INT16_MIN;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j] > max){
                max = arr[i][j];
            }
        }
    }
    return max;
}

// Minimum number in 2D Array
int minNum(int arr[3][4],int row,int col){
    int min = INT16_MAX;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j] < min){
                min = arr[i][j];
            }
        }
    }
    return min;
}

int main(){
    int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int row = 3;
    int col = 4;
    printRowWise(arr,row,col);
    printcolWise(arr,row,col);

    // taking input from user for 2D array
    int arr1[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout << "Enter the element for row index " << i <<" column index " << j << endl;
            cin >> arr1[i][j];
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    // searching in 2D Array
    int key;
    cout << "Enter the element to find: ";
    cin >> key;
    cout << "Found or Not: " << search(arr,row,col,key) << endl;

    cout << "Maximum Element: " << maxNum(arr,row,col) << endl;
    cout << "Minimum Element: " << minNum(arr,row,col) << endl;
}
