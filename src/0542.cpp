#include <bits/stdc++.h>
using namespace std;

 vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    if(n == 0)
        return mat;
    int m = mat[0].size();
    vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
    queue<pair<int,int>>q;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 0){
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    while(!q.empty()){
        pair<int, int>cur = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nr = cur.first + dir[i][0];
            int nc = cur.second + dir[i][1];
            
            if(nr >=0 && nr < n && nc >= 0 && nc < m){
                if(dist[nr][nc] > dist[cur.first][cur.second] + 1){
                    dist[nr][nc] = dist[cur.first][cur.second] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    return dist;
}
