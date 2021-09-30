#include <bits/stdc++.h>
using namespace std;

bool check = true;
    vector<vector<int>>x;
    
    void dfs(int i, int j, vector<vector<int>>&grid2)
    {
        if(i<0 || j<0 || i>=grid2.size() || j>=grid2[0].size()) return;
        
        if(grid2[i][j] == 0) return;
        if(x[i][j] == 0) check = false;
        
        grid2[i][j] = 0;

        
        dfs(i + 1, j, grid2);
        dfs(i - 1, j, grid2);
        dfs(i, j - 1, grid2);
        dfs(i, j + 1, grid2);
}
    
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int row = grid2.size(); //n
    int col = grid2[0].size(); //m

    x = grid1;
    int res = 0;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(grid2[i][j]== 1){
                dfs(i, j, grid2);
                if(check) res++;
                check=true;
            } 
        }
    }
    return res;
}
