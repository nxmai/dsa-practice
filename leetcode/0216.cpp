#include <bits/stdc++.h>
using namespace std;

void backtrack(int start, int target, vector<int>cur, vector<vector<int>>&result, int k){
    if(cur.size() == k && target == 0){
        result.push_back(cur);
        return;
    }
    for(int i = start; i <= 9; i++){
        cur.push_back(i);
        backtrack(i+1, target-i, cur, result, k);
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>>result;
    vector<int>cur;
    
    backtrack(1, n, cur, result, k);
    return result;
}
