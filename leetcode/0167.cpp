#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    int i = 0, j = n - 1;
    
    while(1){
        if(nums[i] + nums[j] == target)
            break;
        else if (nums[i] + nums[j] < target)
            i++;
        else
            j--;
    }
    return vector<int>{i+1, j+1};
    
}