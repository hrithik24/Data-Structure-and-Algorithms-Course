#include<iostream>
#include<vector>
#include <climits>
using namespace std;
vector<int> rowWithMissingOnes(vector<vector<int>>& mat){
    int n = mat.size();
    int onesCount = INT_MIN;
    int rowNo = -1;
    vector<int> ans;
    for(int i=0;i<n;i++){
        int m = mat[i].size();
        int count = 0;
        for(int j=0;j<m;j++){
            if(mat[i][j] == 1){
                count++;
            }
        }

        if(count > onesCount){
            onesCount = count;
            rowNo = i;
        }
    }
    ans.push_back(rowNo);
    ans.push_back(onesCount);
    return ans;
}
int main(){
    vector<vector<int>> mat = {{0,0,0},{0,1,1}};
    vector<int> v = rowWithMissingOnes(mat);
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    
}