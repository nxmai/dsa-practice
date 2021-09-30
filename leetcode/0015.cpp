#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    
    int n = nums.size() - 1, left, right;
    
    for(int i =0; i<=n; i++){
        if(i> 0 && nums[i-1] == nums[i]) continue;
        left = i + 1;
        right = n;
        
        while(left<right){
            if(nums[i] +nums[left] + nums[right] < 0) left++;
            else if(nums[i] +nums[left] + nums[right] > 0) right--;
            else {
                vector<int> tmp{nums[i], nums[left], nums[right]};
                res.push_back(tmp);
                left++;
                while(left<right && nums[left]==nums[left-1]) left++;
                
            }
        }
    }
    
    return res;
    
}