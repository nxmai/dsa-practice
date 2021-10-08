#include <iostream>
#include <vector>

using namespace std;

int findCircleNum(vector<vector<int>>& grid) {
    int n = grid.size();
    
    int provinces=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                provinces++;
                dfs(i,j,grid);
            }
        }
    }
    return provinces;
    
    
}

void dfs(int i,int j,vector<vector<int>>&isConnected){
    isConnected[i][j]=0;
    for(int k=0;k<isConnected.size();k++){
        if(isConnected[j][k]==1){
            dfs(j,k,isConnected);
        }
    }
}