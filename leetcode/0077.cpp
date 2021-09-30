#include<bits/stdc++.h>
using namespace std;

void backtrack(int start, int n, int k, vector<vector<int>>&result, vector<int>cur){
    if(cur.size() == k){
        result.push_back(cur);
        return;
    }
    for(int i = start; i <= n; i++){
        cur.push_back(i);
        backtrack(i+1, n, k, result, cur);
        cur.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>>result;
    vector<int>cur;
    backtrack(1, n, k, result, cur);
    return result;
}