//codeforces
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<char>>level, pair<int, int>s, pair<int, int>f){
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m =level.size();
    int n = level[0].size();

    queue<pair<int,int>>q;
    level[s.first][s.second] = 'X';
    q.push(s);

    while(!q.empty()){
        auto pos = q.front();
        q.pop();

        int u = pos.first;
        int v = pos.second;

        for(auto dir: dirs){
            int a = u + dir[0];
            int b = v + dir[1];

            if(a == f.first && b == f.second && level[a][b] == 'X'){
                return true;
            }

            if(a>=0 && a <m && b>=0 && b<n && level[a][b] == '.'){
                q.push({a, b});
                level[a][b] = 'X';
            }
        }
    }
    return false;
}

int main() {
    int m, n, a, b;
    char c;
    cin >> m >> n;

    vector<vector<char>> level;
    for(int i = 0; i < m; i++){
        vector<char>tmp;
        for(int j = 0; j < n; j++){
            cin >> c;
            tmp.push_back(c);
        }
        level.push_back(tmp);
    }
    pair<int,int>s, f;
    cin >> a >> b;
    s ={a-1, b-1};
    cin >> a >> b;
    f = { a-1, b-1};

    cout << (bfs(level, s, f) ? "YES" : "NO");
    return 0;
}