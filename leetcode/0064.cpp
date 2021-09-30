#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
	if (!row)
		return 0;
	int col = grid[0].size();
	if (!col)
		return 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i == 0 && j > 0)
				grid[i][j] += grid[i][j - 1];
			else if (j == 0 && i > 0)
				grid[i][j] += grid[i - 1][j];
			else if (i > 0 && j > 0)
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
		}
	}
	return grid[row-1][col-1];

}