//spoj
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#define MAX 505

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int>dist(MAX, INT_MAX);
int path[MAX];

struct option{
    bool operator() (const pair<int, int>&a, const pair<int, int>&b) const {
        return a.second > b.second;
    }
};

void dijkstra(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, option> q;
    q.push({s, 0});
    dist[s] = 0;

    while(!q.empty()){
        pair<int, int> top = q.top();
        q.pop();
        int u = top.first;
        int w = top.second;

        for(int i = 0; i < graph[u].size(); i++){
            pair<int, int> neighbor = graph[u][i];
            if(w + neighbor.second < dist[neighbor.first]){
                dist[neighbor.first] = w + neighbor.second;
                q.push(pair<int, int>(neighbor.first, dist[neighbor.first]));
                path[neighbor.first] = u;
            }
        }
    }
}

int main() {
    int n;
    int u, v, w;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }   
    int s;
    cin >> s;

    dijkstra(s);

    int q, a;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> a;
        if(dist[a] != INT_MAX){
            cout << dist[a] << endl;
        } else {
            cout << "NO PATH" << endl;
        }
        
    }
}