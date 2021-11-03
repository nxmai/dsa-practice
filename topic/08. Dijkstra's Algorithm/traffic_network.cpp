//spoj
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <map>
#define MAX 10005

using namespace std;

vector<int>dist;

struct option{
    bool operator()(const pair<int,int>&a, const pair<int, int>&b) const {
        return a.second > b.second;
    }
};

void dijkstra(int s, vector<vector<pair<int, int>>>graph){
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
    int test;
    int n, m, k, s, t;
    int d, c, l;
    int u, v, q;

    cin >> test;
    while(test!=0){
        cin >> n >> m >> k >> s >> t;
        vector<vector<pair<int, int>>>graph_from_s(MAX, vector<pair<int, int>>());
        vector<vector<pair<int, int>>>graph_from_t(MAX, vector<pair<int, int>>());
        dist = vector<int>(MAX, INT_MAX);

        for(int i = 0; i < m; i++){
            cin >> d >> c >> l;
            graph_from_s[d].push_back({c, l});
            graph_from_t[c].push_back({d, l});
        }

        dijkstra(s, graph_from_s);
        vector<int>dist_from_s = dist;

        dist = vector<int>(MAX, INT_MAX);
        dijkstra(t, graph_from_t);

        int res = INT_MAX;
        for(int i = 0; i < k; i++){
            cin >> u >> v >> q;
            if(dist_from_s[u] != INT_MAX && dist[v] != INT_MAX){
                res = min(res, dist_from_s[u] + q + dist[v]);
            }
            if(dist_from_s[v] != INT_MAX && dist[u] != INT_MAX){
                res = min(res, dist_from_s[v] + q + dist[u]);
            }
        }

        if(res != INT_MAX){
            cout << res << endl;
        } else {
            cout << -1 << endl;
        }

        test--;
    }
}