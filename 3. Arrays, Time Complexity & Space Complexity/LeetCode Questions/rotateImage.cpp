#include<iostream>
#include<vector>
#include <climits>
using namespace std;
void reverseVector(vector<int>& v){
    int n = v.size();
    int start = 0;
    int end = n-1;
    while(start < end){
        swap(v[start],v[end]);
        start++;
        end--;
    }
}
vector<int> rotateImage(vector<vector<int>>& mat){
    int n = mat.size();

    // transpose of 2Dmatrix
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }

    // reverse the matrix
    for(int i=0;i<n;i++){
        reverseVector(mat[i]);
    }

    // printing the matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    rotateImage(mat);

}