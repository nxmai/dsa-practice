#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    
    int res = INT_MAX, sum;
    int lo, hi;
    int n = nums.size();
    
    for(int i = 0; i < n; i++){
        lo = i + 1; hi = n - 1;
        while(lo < hi){
            sum = nums[i] + nums[lo] + nums[hi];
            if(abs(sum-target) < abs(res)){
                res = target - sum;
            }
            if(sum < target)
                lo++;
            else
                hi--;
        }
    }
    
    return target - res;
}