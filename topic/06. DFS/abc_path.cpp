//spoj
#include <iostream>
#include <vector>
#define MAX 55

using namespace std;

vector<vector<char>>graph;
vector<vector<bool>>visited;

vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
int ans;
int res;
int r, c;

void dfs(int i, int j, int cur, int ans){
    //cout << "i " << i << " j " << j <<endl;

    for(auto dir : dirs){
        int u = i + dir[0];
        int v = j + dir[1];

        if(u>=0 && u<r && v>=0 && v<c && !visited[u][v] && (int)graph[u][v] == cur+1){
            visited[u][v] = true;
            dfs(u, v, cur+1, ans+1);
            visited[u][v] = false;
        }
    }
    
    res=max(res, ans);
}

int main() {
    char a;
    int cnt = 1;

    cin >> r >> c;
    while(r!=0 && c!=0){
        graph.clear();
        for(int i = 0; i < r; i++){
            vector<char>tmp;
            for(int j = 0; j < c; j++){
                cin >> a;
                tmp.push_back(a);
            }
            graph.push_back(tmp);
        }

        visited.assign(MAX, vector<bool>(MAX, false));

        ans = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(graph[i][j] == 'A'){
                    res = 0;
                    visited[i][j] = true;
                    dfs(i, j, (int)graph[i][j], 1);
                    ans = max(ans, res);
                  visited[i][j] = false;
                    //cout  << " res " << res << endl;
                }
            }
        }
        cout << "Case " << cnt++ << ": " << ans <<endl;

        cin >> r >> c;
    }
}