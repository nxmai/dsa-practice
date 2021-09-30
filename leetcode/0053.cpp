#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int cur = 0;
    int val = INT_MIN;
    
    for(int i = 0; i < nums.size(); i++){
        cur += nums[i];
        
        if(cur < nums[i])
            cur = nums[i];
        val = max(val, cur);    
    }
    
    return val;
}