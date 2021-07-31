#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<char>>&grid)
{
	grid[i][j] = '0';

	if (i + 1 < grid.size() && grid[i + 1][j] == '1')
		dfs(i + 1, j, grid);
	if (i - 1 >= 0 && grid[i - 1][j] == '1')
		dfs(i - 1, j, grid);
	if (j - 1 >= 0 && grid[i][j - 1] == '1')
		dfs(i, j - 1, grid);
	if (j + 1 < grid[0].size() && grid[i][j + 1] == '1')
		dfs(i, j + 1, grid);
}

int numIslands(vector<vector<char>>& grid) {
    int row = grid.size();
    if(row==0)
        return 0;
	int col = grid[0].size();

	if (col == 0)
		return 0;

	int res = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
            if(grid[i][j]=='1'){
			    res++;
			    dfs(i, j, grid);
            }
		}
	}
	return res;
}