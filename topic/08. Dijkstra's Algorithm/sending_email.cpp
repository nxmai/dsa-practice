//uva
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <map>
#define MAX 10005

using namespace std;

vector<vector<pair<int, int>>>graph;
vector<int>dist;

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
            }
        }
    }
}

int main(){
    int q;
    int n, m, s, t;
    int u, v, w;

    cin >> q;
    for(int j = 1; j <= q; j++){
        cin >> n >> m >> s >> t;
        graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
        dist = vector<int>(MAX, INT_MAX);

        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        dijkstra(s);
        if(dist[t] != INT_MAX){
            cout << "Case #" << j << ": " << dist[t] << endl;
        } else {
            cout << "Case #" << j << ": unreachable" << endl;
        }

    }
}