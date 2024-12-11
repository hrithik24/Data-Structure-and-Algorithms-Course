#include<iostream>
#include<vector>
using namespace std;
int findPivotElement(vector<int>& nums){
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    int mid;
    while(start <= end){
        mid = start + (end - start) / 2;
        // Edge Case
        if(start == end){
            return start;
        }
        // mid+1 < n  and mid-1 >= 0 is the edge cases
        if(mid+1 < n && nums[mid] > nums[mid+1]){
            return mid;
        }
        else if(mid-1 >=0 && nums[mid-1] > nums[mid]){
            return mid-1;
        }
        // condition for B part
        else if(nums[start] > nums[mid]){
            end = mid - 1;
        }
        // condition for A part
        else{
            start = mid + 1;
        }
    }
    return -1;
}

int binarySearch(vector<int>& nums,int start,int end,int target){
    int n = nums.size();
    int mid;
    while(start <= end){
        mid = start + (end - start) / 2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
}

int search(vector<int>& nums, int target){
    int pivotIndex = findPivotElement(nums);
    int n = nums.size();
    int ans = -1;
    // searching in A Part
    if(target >= nums[0] && target <= nums[pivotIndex]){
        ans = binarySearch(nums,0,pivotIndex,target);
    }
    // searching in B Part
    else{
        ans = binarySearch(nums,pivotIndex+1,n-1,target);
    }
    return ans;
}
int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 6;
    cout << "Element found at index: " << search(nums,target);
}