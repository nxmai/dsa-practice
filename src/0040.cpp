#include<bits/stdc++.h>
using namespace std;

void backtrack(int start, int target, vector<int>cur, vector<vector<int>>&result, vector<int>cand){
    if(target<0)
        return;
    if(target==0)
        result.push_back(cur);
    
    for(int i = start; i < cand.size(); i++){
        if(i>start && cand[i] == cand[i-1])
            continue;
        
        cur.push_back(cand[i]);
        backtrack(i + 1, target - cand[i], cur, result, cand);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>result;
    vector<int>cur;
    sort(candidates.begin(), candidates.end());
    
    backtrack(0, target, cur, result, candidates);
    return result;
}