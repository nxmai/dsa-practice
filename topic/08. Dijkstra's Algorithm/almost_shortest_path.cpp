//uva
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <map>
#define MAX 505

using namespace std;

vector<int>dist;

struct option{
    bool operator()(const pair<int,int>&a, const pair<int, int>&b) const {
        return a.second > b.second;
    }
};

void dijkstra(int s, vector<vector<pair<int, int>>>graph){
    vector<vector<pair<int,int>>>paths;
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
    int n, m, s, d;
    int u, v, p;

    cin >> n >> m;
    while(n!=0 && m!=0){
        cin >> s >> d;
        dist = vector<int>(MAX, INT_MAX);
        vector<vector<pair<int, int>>>graph_s(MAX, vector<pair<int,int>>());
        vector<vector<pair<int, int>>>graph_d(MAX, vector<pair<int,int>>());

        for(int i = 0; i < m; i++){
            cin >> u >> v >> p;
            graph_s[u].push_back({v, p});
            graph_d[v].push_back({u, p});
        }

        dijkstra(s, graph_s);
        int min_sd = dist[d];
        vector<int>min_from_s = dist;

        dist = vector<int>(MAX, INT_MAX);
        dijkstra(d, graph_d);
        vector<int>min_from_d = dist;

        vector<vector<pair<int,int>>>new_graph(MAX, vector<pair<int,int>>());
        for(int i = 0; i < n; i++){
            for(pair<int, int>& neighbor : graph_s[i]){
                int v = neighbor.first;
                int w = neighbor.second;

                if(min_from_s[i] + w + min_from_d[v] != min_sd){
                    new_graph[i].push_back(neighbor);
                }
            }
        }

        dist = vector<int>(MAX, INT_MAX);
        dijkstra(s, new_graph);

        if(dist[d] == INT_MAX){
            cout << -1 << endl;
        } else {
            cout << dist[d] << endl;
        }
       

        cin >> n >> m;
    }
}