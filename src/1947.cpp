#include <bits/stdc++.h>
using namespace std;

int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
    int n = students.size();
    
    int ans = 0;
    vector<int>pos;
    for(int i = 0; i < n; i++){
        pos.push_back(i);
    }
    
    do{
        int cur = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < students[pos[i]].size(); j++){
                cur += (students[pos[i]][j] == mentors[i][j]);
            }
        }
        ans = max(ans, cur);
    }while(next_permutation(pos.begin(), pos.end()));
    return ans;
}