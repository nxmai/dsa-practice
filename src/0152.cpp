#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    int res = nums[0];
    int minCur = nums[0], maxCur = nums[0];
    int tmp;
    
    for(int i = 1; i < nums.size(); i++){
        tmp = maxCur;
        maxCur = max(nums[i], max(nums[i]*maxCur, nums[i]*minCur));
        minCur = min(nums[i], min(nums[i]*minCur, nums[i]*tmp));
        
        res = max(maxCur, res);
    }
    
    return res;
}