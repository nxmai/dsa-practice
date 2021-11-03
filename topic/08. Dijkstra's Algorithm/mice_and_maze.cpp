//spoj
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#define MAX 105

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int>dist(MAX, INT_MAX);
int path[MAX];

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

        for(int i = 0; i < graph[v].size(); i++){
            pair<int, int>neighbor = graph[v][i];
            if(w + neighbor.second < dist[neighbor.first]){
                dist[neighbor.first] = w + neighbor.second;
                q.push({neighbor.first, dist[neighbor.first]});
                path[neighbor.first] = v;
            }
        }
    }
}

int main () {
    int n, e, t, m;
    cin >> n >> e >> t >> m;
    int a, b, w;

    graph = vector<vector<pair<int,int>>>(MAX, vector<pair<int,int>>());
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        graph[b].push_back({a, w});
    }

    dijkstra(e);
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] <= t){
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}