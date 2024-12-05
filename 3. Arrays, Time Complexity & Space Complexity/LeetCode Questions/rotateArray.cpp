#include<iostream>
#include<vector>
using namespace std;
void rotateArray(vector<int>& nums, int k){
    int n = nums.size();
    vector<int> ans(n);
    for(int index = 0;index<n;index++){
        int newIndex = (index+k)%n;
        ans[newIndex] = nums[index];
    }
    nums = ans;
}
int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k;
    cout << "Enter the value of K: ";
    cin >> k;
    rotateArray(nums,k);
    cout << "Printing Vector after rotating: ";
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }  
}