#include<iostream>
#include<vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target){
    int row = matrix.size();
    int col = matrix[0].size();
    int n = row * col;

    int start = 0;
    int end = n - 1;
    int mid;
    while(start <= end){
        mid = start + (end - start) / 2;
        int rowIndex = mid/col;
        int colIndex = mid%col;
        int currNumber = matrix[rowIndex][colIndex];

        if(currNumber == target){
            return true;
        }
        else if(currNumber < target){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return false;

}
int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60},{23,30,34,60}};
    int target = 35;
    cout << searchMatrix(matrix,target);
}