#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    int sum = 0;
    
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        nums[i] = sum;
    }
    
    return nums;
}