#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<int>candidates, int start, int target, vector<int>tmp, vector<vector<int>> &result) {
    if(target < 0)
        return;
    if(target == 0)
        result.push_back(tmp);
    
    for(int i = start; i < candidates.size(); i++){
        tmp.push_back(candidates[i]);
        backtrack(candidates, i, target - candidates[i], tmp, result);
        tmp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int>tmp;
    backtrack(candidates, 0, target, tmp, result);
    return result;
}