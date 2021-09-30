#include <bits/stdc++.h>
using namespace std;

int maximumDifference(vector<int>& nums) {
    int n = nums.size();
    vector<int> maxOnRight(n, 0);
    maxOnRight[n - 1] = nums[n - 1];

    for(int i = n - 2; i >= 0; i--){
        maxOnRight[i] = max(maxOnRight[i + 1], nums[i]);           
    }
    
    int res = -1;
    for(int i = 0; i < n - 1; i++){
        if(nums[i] < maxOnRight[i+1]){
            res = max(res, maxOnRight[i+1] - nums[i]);
        }
    }
    
    return res;
}