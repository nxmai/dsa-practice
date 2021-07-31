#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int val;
    int n = nums.size() - 1;
    int mid, left = 0, right = n;
    
    if(nums.size() == 1)
        return nums[0];
    if(nums[0] < nums[n])
        return nums[0];
    if(nums[n] < nums[n-1])
        return nums[n];
    
    while(left < right){
        mid=(left+right)/2;
        if(nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]){
            val = nums[mid];
            break;
        }
        if(nums[mid] > nums[0])
            left = mid;
        else
            right = mid;
        
    }
    return val;
}