//spoj
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void slicks(vector<vector<int>>sea, int m, int n){
    int cnt = 0;

    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    vector<int>res = {};
    int large = 0;

    queue<pair<int, int>> q;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(sea[i][j] == 1){
                cnt++;
                q.push({i, j});

                while(!q.empty()){
                    large++;
                    auto pos = q.front();
                    q.pop();

                    int u = pos.first;
                    int v = pos.second;

                    sea[u][v] = 0;
                    for(auto dir : dirs){
                        int a = u + dir[0];
                        int b = v + dir[1];

                        if(a>=0 && a<m && b>=0 && b<n && sea[a][b] == 1){
                            sea[a][b] = 0;
                            q.push({a, b});
                        }
                    }
                }
                res.push_back(large);
                large = 0;
            }
        }
    }
    sort(res.begin(), res.end());
    int fre = 1;
    
    cout << cnt <<endl;
    for(int i = 1; i < res.size(); i++){
        if(res[i] == res[i-1]){
            fre++;
        } else {
            cout << res[i-1] << " " <<fre <<endl;
            fre = 1;
        }
    }
    if(res.size() >= 1){
        cout << res[res.size() -1] << " " <<fre <<endl;
    }
    
}

int main() {
    int m, n;
    int a;
    

    cin >> m >> n;
    while(m!=0 && n != 0){
        vector<vector<int>>sea;
        for(int i = 0; i < m; i++){
            vector<int>tmp;
            for(int j = 0; j < n;j++){
                cin >>a;
                tmp.push_back(a);
            }
            sea.push_back(tmp);
        }
        slicks(sea, m, n);
        cin >> m >> n;
    }
}