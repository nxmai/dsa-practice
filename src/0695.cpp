#include <bits/stdc++.h>
using namespace std;

void recur(vector<vector<int>>& grid, int i, int j, int& tmp){
    grid[i][j] = -1;
    tmp += 1;

    if(i+1 < grid.size() && grid[i+1][j] == 1)
        recur(grid, i+1, j, tmp);
    
    if(i-1 >= 0 && grid[i-1][j] == 1)
        recur(grid, i-1, j, tmp);
    
    if(j-1 >= 0 && grid[i][j-1] == 1)
        recur(grid, i, j-1, tmp);
    
    if(j+1 < grid[0].size() && grid[i][j+1] == 1)
        recur(grid, i, j+1, tmp);
    
}


int maxAreaOfIsland(vector<vector<int>>& grid) {
    int val = 0, tmp = 0;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] == 1){
              tmp = 0;
              recur(grid, i, j, tmp);
              val = max(val, tmp);
            }
        }
    }
    return val;
}