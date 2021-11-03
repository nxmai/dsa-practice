//kattis
#include <bits/stdc++.h>
#define MAX 1005
const int INF = 1e9 + 7;

using namespace std;

struct Edge{
    int source;
    int target;
    int weight;

    Edge(int source = 0, int target = 0, int weight = 0){
        this->source = source;
        this->target = target;
        this->weight = weight;
    }
};

int n, m;
vector<int>dist;
vector<Edge>graph;

void bellmanFord(int s){
    int u, v, w;
    dist[s] = 0;
    for(int i = 1; i <= n-1; i++){
        for(int j = 0; j < m; j++){
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;

            if(dist[u] != INF && (dist[u] + w < dist[v])){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int j = 0; j < n - 1; j++){
        for(int i = 0; i < m; i++){
            u = graph[i].source;
            v = graph[i].target;
            w = graph[i].weight;

            if(dist[u] != INF && (dist[u] + w < dist[v])){
                dist[v] = -INF;
            }
        }
    }
    
}

int main(){
    int q, t;
    int u, v, w;
    int e;

    cin >> n >> m >> q >> t;
    while(!(n==0 && m==0 && q==0 && t==0)){
        dist = vector<int>(MAX, INF);
        graph.clear();

        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            graph.push_back(Edge(u, v, w));
        }

        bellmanFord(t);
        for(int i = 0; i < q; i++){
            cin >> e;
            if(dist[e] == INF)
                cout << "Impossible" << endl;
            else if(dist[e] == -INF)
                cout << "-Infinity" << endl;
            else 
                cout << dist[e] << endl;
        }
      	cout << endl;

        cin >> n >> m >> q >> t;
    }
}

