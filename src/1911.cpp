#include <bits/stdc++.h>
using namespace std;

long long maxAlternatingSum(vector<int>& nums) {
    int n = nums.size();
    long int res = nums[0];
    
    for(int i = 1; i < nums.size(); i++){
        res += max(nums[i] - nums[i-1], 0);
    }
    return res;
}