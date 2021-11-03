//spoj
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void check(vector<vector<char>>maze, int m, int n){
    int cnt = 0;
    vector<pair<int,int>>pos;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(maze[i][j] == '.' && (i==0 || j==0 || i == m-1 || j==n-1)){
                cnt++;
                pos.push_back({i, j});
            }
        }
    }
    
    
    if(cnt != 2){
        cout << "invalid" << endl;
        return;
    }

    pair<int, int> start = pos[0];
    pair<int, int> end = pos[1];
    queue<pair<int, int>>q; // add .
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    q.push(start);
    while(!q.empty()) {
        auto front = q.front();
        q.pop();

        int u = front.first;
        int v = front.second;

        maze[u][v] = '#';
        for(auto dir: dirs){
            int a = u + dir[0];
            int b = v + dir[1];
            if(a >= 0 && a < m && b >= 0 && b < n && maze[a][b] == '.'){
                maze[a][b] = '#';
                if(a == end.first && b == end.second){
                    cout << "valid" << endl;
                    return;
                }
                q.push({a, b});
            }
        }
    }

    cout << "invalid" << endl;
    return;
}

int main() {
    int t;
    int m, n;
    vector<vector<char>>maze;
    char c;

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> m >> n;
        maze.clear();
        
        for(int i = 0; i < m; i++){
            vector<char>tmp;
            for(int j = 0; j < n; j++){
                cin >> c;
                tmp.push_back(c);
            }
            maze.push_back(tmp);
        }
        check(maze, m, n);
    }

    return 0;
}