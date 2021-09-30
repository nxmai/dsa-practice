#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>>&result, vector<int>cur, vector<int>nums, int start){
    result.push_back(cur);
    
    for(int i = start; i < nums.size(); i++){
        if(i>start && nums[i] == nums[i-1])
            continue;
        
        cur.push_back(nums[i]);
        backtrack(result, cur, nums, i + 1);
        cur.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>>result;
    vector<int>cur;
    
    sort(nums.begin(), nums.end());
    
    backtrack(result, cur, nums, 0);
    
    return result;
}