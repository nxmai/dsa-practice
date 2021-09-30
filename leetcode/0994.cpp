#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>>q;
    int fresh = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({i, j});
            }
            if(grid[i][j] == 1){
                fresh++;
            }
        }
    }
    
    if(fresh == 0)
        return 0;
    
    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    int cnt = -1;
    while(!q.empty()){
        int len = q.size();
        while(len){
            pair<int, int>cur = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = cur.first + dir[i][0];
                int nc = cur.second + dir[i][1];

                if(nr >=0 && nr < n && nc >= 0 && nc < m){
                    if(grid[nr][nc] == 1){
                        fresh--;
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            
            len--;
        }
        
        cnt++;
    }
    if(fresh == 0)
        return cnt;
    return -1;
}
