#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>>&result, vector<int>nums, vector<int>cur, vector<bool>check){
    if(nums.size() == cur.size()){
        result.push_back(cur);
        return;
    }
    
    for(int i = 0; i < nums.size(); i++){
        if(check[i])
            continue;
        
        check[i] = true;
        cur.push_back(nums[i]);
        backtrack(result, nums, cur, check);
        cur.pop_back();
        check[i] = false;
    }
    
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>result;
    vector<int>cur;
    vector<bool>check(nums.size(), false);
    
    backtrack(result, nums, cur, check);
    
    return result;
}