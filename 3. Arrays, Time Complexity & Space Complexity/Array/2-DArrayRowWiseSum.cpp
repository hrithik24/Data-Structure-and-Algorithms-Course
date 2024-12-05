#include<iostream>
using namespace std;
void rowWiseSum(int arr[3][4],int row,int col){
    for(int i=0;i<row;i++){
        int sum = 0;
        for(int j=0;j<col;j++){
            sum = sum + arr[i][j];
        }
        cout << sum << " ";
    }
    cout << endl;

}

void colWiseSum(int arr[3][4],int row,int col){
    for(int i=0;i<col;i++){
        int sum = 0;
        for(int j=0;j<row;j++){
            sum = sum + arr[j][i];
        }
        cout << sum << " ";
    }
    cout << endl;

}

void diagonalWiseSum(int arr[4][4],int row,int col){
    int sum = 0;
    for(int i=0;i<row;i++){
        sum = sum + arr[i][i];  
    }
    cout << sum;
}

int main(){
    int arr[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int row = 3;
    int col = 4;
    rowWiseSum(arr,row, col);
    colWiseSum(arr,row,col);
    int arr1[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16} };
    int r1 = 4;
    int c1 = 4;
    diagonalWiseSum(arr1,r1,c1);
}
