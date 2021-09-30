#include <bits/stdc++.h>
using namespace std;

bool canBeIncreasing(vector<int>& nums) {
    int count = 0;
    int index = -1;
    int n = nums.size();
    
    for(int i = 1; i < n ; i++){
        if(nums[i] <= nums[i-1]){
            count++;
            index = i;
        }
    }
    
    if(count > 1)
        return false;
    
    if (count == 0)
        return true;
    
    if (index == n - 1 || index == 1)
        return true;
    
    if (nums[index - 1] < nums[index + 1])
        return true;
    
    if (nums[index - 2] < nums[index])
        return true;

    return false;
}