#include<bits/stdc++.h>
using namespace std;

void swap(vector<int>&nums, int i, int j){
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void reverse(vector<int>&nums, int start){
    int i = start, j = nums.size() - 1;
    while(i < j){
        swap(nums, i, j);
        i++;
        j--;
    }
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    
    int i = n - 2;
    while( i>=0 && nums[i+1] <= nums[i])
        i--;
    
    if(i>=0){
        int j = n - 1;
        while(nums[j] <= nums[i])
            j--;
    
        swap(nums, i, j);
    }
    
    
    reverse(nums, i+1);
}