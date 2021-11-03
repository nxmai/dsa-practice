//lightoj
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int count (vector<vector<char>> vt, int n, int m){
    pair<int,int>start;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(vt[i][j] == '@'){
                start = {i, j};
                break;
            }
        }
    }

    queue<pair<int,int>> q;
    q.push(start);

    int cnt = 0;
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    while(!q.empty()){
        auto pos = q.front();
        q.pop();
        cnt ++;

        int u = pos.first;
        int v = pos.second;

        // vt[u][v] = '#';
        for(auto dir : dirs){
            int a = u + dir[0];
            int b = v + dir[1];
            if(a >= 0 && a < m && b >= 0 && b < n && vt[a][b] == '.'){
                q.push({a, b});
                vt[a][b] = '#';
            }
        }
    }
    return cnt;
}

int main() {
    int t;
    int m, n;
    char c;

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        vector<vector<char>> vt;
        for(int j = 0; j < m; j++){
            vector<char> tmp;
            for(int k = 0; k < n; k++){
                cin >> c;
                tmp.push_back(c);
            }
            vt.push_back(tmp);
        }
        cout << "Case " << i + 1 << ": " << count(vt, n, m) << endl;
    }

    return 0;
}