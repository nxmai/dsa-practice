#include <bits/stdc++.h>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
        
    for(int i = 1; i < nums.size(); i++){
        nums[i] = nums[i-1] + nums[i]; 
    }
    
    double res = nums[k-1]*1.0/k;
    
    for(int i = k; i < nums.size(); i++){
        res = max(res, (nums[i] - nums[i-k])*1.0/k);
    }
    
    return res;

}