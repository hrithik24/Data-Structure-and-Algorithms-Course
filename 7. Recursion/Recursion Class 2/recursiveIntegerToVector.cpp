#include<iostream>
#include<vector>
using namespace std;
void intToVector(int n,vector<int> &ans){
    // base case
    if(n == 0){
        return;
    }

    // processing
    int a = n % 10;
    n = n/10;

    // recursive call
    intToVector(n,ans);

    ans.push_back(a);
}

// vector to integer
void vectorToInteger(vector<int> ans,int index,int &num){
    // base case
    if(index >= ans.size()){
        return;
    }

    // processing
    num = num * 10 + ans[index];

    // recursive call
    vectorToInteger(ans,index+1,num);
}
int main(){
    // int n = 4512;
    // vector<int> ans;
    // intToVector(n,ans);
    // for(int i=0;i<ans.size();i++){
    //     cout << ans[i] << " ";
    // }
    vector<int> ans = {4,2,1,7};
    int num = 0;
    int index = 0;
    vectorToInteger(ans,index,num);
    cout << num;


}