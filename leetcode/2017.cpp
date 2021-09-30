#include <bits/stdc++.h>
using namespace std;

long long gridGame(vector<vector<int>>& grid) {
    long long sRight = 0, sLeft = 0;
    
    for(int j = 1; j < grid[0].size(); j++){
        sRight += grid[0][j];
    }
    long long res = sRight;
    
    for(int j = 1; j < grid[0].size(); j++){
        sRight -= grid[0][j];
        sLeft += grid[1][j-1];
        res = min(res, max(sRight, sLeft));
    }
    
    return res;
}