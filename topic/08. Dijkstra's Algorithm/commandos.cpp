//lightoj
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <map>
#define MAX 105

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

int main() {
    int t;
    int n, r;
    int u, v;
    int s, d;

    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        cin >> r;
        graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int,int>>());

        while(r!=0){
            cin >> u >> v;
            graph[u].push_back({v, 1});
            graph[v].push_back({u, 1});
            r--;
        }

        dist = vector<int>(MAX, INT_MAX);
        cin >> s >> d;
        dijkstra(s);
        vector<int>dist_tmp = dist;

        dist = vector<int>(MAX, INT_MAX);
        dijkstra(d);

        int res = 0;
        for(int j = 0; j < n; j++){
            res = max(res, dist[j] + dist_tmp[j]);
        }

        cout << "Case " << i << ": " << res << endl;
    }
}