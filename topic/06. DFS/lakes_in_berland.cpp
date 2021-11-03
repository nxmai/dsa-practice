//codeforces
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<vector<bool>>visited(51, vector<bool>(51, false));

bool isValid(int a, int b){
    return (a==0 || b==0 || a == m-1 || b==n-1);
}

int dfs1(int i, int j, vector<vector<char>> grid, bool &open){
    if(isValid(i, j)){
        open = true;
    }
    visited[i][j] = true;
  int cnt = 1;
    
    if (i + 1 < m && grid[i + 1][j] == '.' && !visited[i+1][j])
		cnt += dfs1(i + 1, j, grid, open)  ;

	if (i - 1 >= 0 && grid[i - 1][j] == '.' && !visited[i-1][j])
		cnt +=  dfs1(i - 1, j, grid, open);

	if (j - 1 >= 0 && grid[i][j - 1] == '.' && !visited[i][j-1])
		cnt += dfs1(i, j - 1, grid, open) ;

	if (j + 1 < n && grid[i][j + 1] == '.' && !visited[i][j+1])
		cnt += dfs1(i, j + 1, grid, open) ;

    return cnt;
}

void dfsDel(int i, int j, vector<vector<char>> & grid){
    grid[i][j] = '*';
    
    if (i + 1 < m && grid[i + 1][j] == '.' )
		dfsDel(i + 1, j, grid)  ;

	if (i - 1 >= 0 && grid[i - 1][j] == '.' )
		dfsDel(i - 1, j, grid) ;

	if (j - 1 >= 0 && grid[i][j - 1] == '.' )
		dfsDel(i, j - 1, grid) ;

	if (j + 1 < n && grid[i][j + 1] == '.')
		dfsDel(i, j + 1, grid) ;
}

bool compare(pair<int,pair<int,int>>&a, pair<int,pair<int,int>>&b){
    return (a.first > b.first);
}

void dfs(int i, int j, vector<vector<char>> grid, bool& open, int &cnt){
    visited[i][j] = true;
    if(isValid(i, j)){
        open = true;
    }
    cnt++;
    
    if (i + 1 < m && grid[i + 1][j] == '.' && !visited[i+1][j])
		dfs(i + 1, j, grid, open, cnt) ;

	if (i - 1 >= 0 && grid[i - 1][j] == '.' && !visited[i-1][j])
		dfs(i - 1, j, grid, open, cnt) ;

	if (j - 1 >= 0 && grid[i][j - 1] == '.' && !visited[i][j-1])
		dfs(i, j - 1, grid, open, cnt) ;

	if (j + 1 < n && grid[i][j + 1] == '.' && !visited[i][j+1])
		dfs(i, j + 1, grid, open, cnt) ;
}

int main() {
    int k;
    char c;
    cin >> m >> n;
    cin >> k;

    vector<vector<char>>land;
    for(int i = 0; i < m; i++){
        vector<char>tmp;
        for(int j = 0; j < n; j++){
            cin >> c;
            tmp.push_back(c);
        }
        land.push_back(tmp);
    }

    vector<pair<int, pair<int,int>>>pos;  //store size and start position
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(land[i][j] == '.' && !visited[i][j]){
                bool open = false;
                int cnt = dfs1(i, j, land, open);
                
                if(!open)
                    pos.push_back({cnt, {i, j}});
            }
        }
    }

    int sumSize = 0;
    sort(pos.begin(), pos.end(), compare);


    for(int i = k; i < pos.size(); i++){
        sumSize += pos[i].first;

        int u = pos[i].second.first;
        int v = pos[i].second.second;
        dfsDel(u, v, land);
    }

    cout << sumSize << endl ;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << land[i][j];
        }
        cout << endl;
    }

    return 0;
}
