#include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int first = INT_MAX, second = INT_MAX;
    
    for(int i = 0; i < nums.size(); i++){
        if(nums[i]<first) first = nums[i];
        else if(first < nums[i] && nums[i] < second) second = nums[i];
        else if(nums[i] > second) return true;
    }
    
    return false;
}