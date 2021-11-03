//hackkerank
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int>arrU, vector<int>arrV, int n, int s){
    vector<bool>visited(n + 1, false);
    vector<int>dist(n + 1, -1);

    queue<int>q;
    visited[s] = true;
    dist[s] = 0;

    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < arrU.size(); i++){
            if(arrU[i] == u || arrV[i] == u){
                int v;
                v = (arrU[i] == u) ? arrV[i] : arrU[i];

                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                    dist[v] = dist[u] + 1;
                }
            } 
        }
    }

    for(int i = 1; i < dist.size(); i++){
        if(i == s)
            continue;
        if(dist[i] == -1)
            cout << -1 << " ";
        else 
            cout << dist[i] * 6 << " ";
    }
    cout << endl;
}

int main() {
    int q;
    int n, m;
    vector<int>u;
    vector<int>v;
    int e1, e2;
    int s;

    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> n >> m;
        u.clear();
        v.clear();
        
        for(int j = 0; j < m; j++){
            cin >> e1 >> e2;
            u.push_back(e1);
            v.push_back(e2);
        }
        cin >> s;
        bfs(u, v, n, s);
    }

    return 0;
}
