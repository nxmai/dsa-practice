//hackerearth
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <map>
#define MAX 100000 + 5

using namespace std;

vector<vector<pair<int, int>>>graph;
vector<int>dist;
vector<bool>have_choco;

struct option{
    bool operator()(const pair<int,int>&a, const pair<int, int>&b) const {
        return a.second > b.second;
    }
};

void dijkstra(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, option>q;
    q.push({s, 0});
    dist[s] = 0;

    while(!q.empty()){
        pair<int, int>top = q.top();
        q.pop();
        int v = top.first;
        int w = top.second;

        if(dist[v] != w)
            continue;

        for(int i = 0; i < graph[v].size(); i++){
            pair<int, int>neighbor = graph[v][i];
            if(w + neighbor.second < dist[neighbor.first]){
                dist[neighbor.first] = w + neighbor.second;
                q.push({neighbor.first, dist[neighbor.first]});
            }
        }
    }
}

int main() {
    int n, m, k, x;
    int u, v, d;
    int a, b;

    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int,int>>());
    dist = vector<int>(MAX, INT_MAX);
    have_choco = vector<bool>(MAX, false);

    cin >> n >> m >> k >> x;

    for(int i = 0; i < k; i++){
        cin >> u;
        have_choco[u] = true;
    }

    for(int i = 0; i < m; i++){
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    cin >> a >> b;
    dijkstra(a);
    vector<int> dist_from_b = dist;
    
    dist = vector<int>(MAX, INT_MAX);
    dijkstra(b);

    int res = INT_MAX;
    for(int i = 1; i <= n; i++){
        if(have_choco[i] && dist[i] <= x && dist_from_b[i] != INT_MAX){
            res = min(res, dist_from_b[i] + dist[i]);
        }
    }
    if(res != INT_MAX){
        cout << res;
    } else {
        cout << -1;
    }

}
