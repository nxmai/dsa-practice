#include <bits/stdc++.h>
using namespace std;

vector<int> buildArray(vector<int>& nums) {
    int n = nums.size();
    int mod = 1001;
    
    for(int i = 0; i < n; i++){
        nums[i] = nums[i] + (nums[nums[i]]%mod)*mod;
    }
    
    for(int i = 0; i< n; i++){
        nums[i] /= mod;
    }
    
    return nums;
}