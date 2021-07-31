#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>>&result, vector<int>cur, vector<int>nums, vector<bool>check){
    if(nums.size() == cur.size()){
        result.push_back(cur);
        return;
    }
    
    for(int i = 0; i < nums.size(); i++){
        
        if(check[i])
            continue;
        
        if(i>0 && check[i-1] && nums[i] == nums[i-1])
            continue;
        
        check[i] = true;
        cur.push_back(nums[i]);
        backtrack(result, cur, nums, check);
        check[i] = false;
        cur.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>>result;
    vector<int>cur;
    vector<bool>check(nums.size(), false);
    
    sort(nums.begin(), nums.end());
    
    backtrack(result, cur, nums, check);
    
    
    return result;
}