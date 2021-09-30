#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>>&result, vector<int>cur, vector<int>nums, int k, int start){
    if(cur.size()==k){
        result.push_back(cur);
        return;
    }
    
    for(int i = start; i < nums.size(); i++){
        cur.push_back(nums[i]);
        backtrack(result, cur, nums, k, i+1);
        cur.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>result;
    vector<int>cur;
    
    for(int i = 0; i < nums.size() + 1; i++){
        backtrack(result, cur, nums, i, 0);
    }
    return result;
}