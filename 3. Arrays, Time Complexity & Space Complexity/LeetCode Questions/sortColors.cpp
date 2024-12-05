#include<iostream>
#include<vector>
using namespace std;
void sortColors(vector<int>& nums){
    int n = nums.size();
    int index = 0,left = 0;
    int right = n-1;
    while(index <= right){
        if(nums[index] == 0){
            swap(nums[index],nums[left]);
            index++;
            left++;
        }
        else if(nums[index] == 2){
            swap(nums[index],nums[right]);
            right--;
        }
        else{
            index++;
        }
    }
}
int main(){
    vector<int> nums = {2,0,2,1,1,0};
    cout << "Printing Vector before sort colors: ";
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }  
    cout << endl;
    sortColors(nums);
    cout << "Printing Vector after sort colors: ";
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }  
}