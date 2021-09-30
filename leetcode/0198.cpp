#include <bits/stdc++.h>
using namespace std;

int dp[101];
int dyp(vector<int>nums, int n){
    if(n<0){
        return 0;
    } else if(dp[n] != -1){
        return dp[n];
    } else{
        return dp[n] = max(dyp(nums, n-1), dyp(nums, n-2) + nums[n]);
    }
}

int rob(vector<int>& nums) {
    int n = nums.size() - 1;
    memset(dp, -1, sizeof(dp));
    
    return dyp(nums, n);
}