#include <bits/stdc++.h>
using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int res =0;
    int tmp = 0;
    for(int i = 0; i < accounts.size(); i++){
        tmp=0;
        for(int j = 0; j < accounts[i].size(); j++){
            tmp += accounts[i][j];
        
        }
        
        res=max(res, tmp);
    }
    
    return res;
}