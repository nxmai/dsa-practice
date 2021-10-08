#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 0;
    int res = INT_MAX;
    int tmp = 0;
    
    while(j < n){
        tmp += nums[j];
        
        while(tmp >= target){
            tmp -= nums[i];
            res = min(res, j - i + 1);
            i++;
        }
        
        j++;
    }
    
    return (res != INT_MAX) ? res : 0;
}