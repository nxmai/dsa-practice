//uva
#include <iostream>
#include <vector>
#include <limits.h>
#define MAX 1005

using namespace std;

vector<int> dist;
int n, m;

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

vector<Edge>graph;

bool bellmanFord(int s){
    int u, v, w;
    dist[s] = 0;
    for(int i = 1; i <= n - 1; i++){
        for(int j = 0; j < m; j++){
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;

            if(dist[u] != INT_MAX && (dist[u] + w < dist[v])){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int i = 0; i < m; i++){
        u = graph[i].source;
        v = graph[i].target;
        w = graph[i].weight;

        if(dist[u] != INT_MAX && (dist[u] + w < dist[v]))
            return false;
    }
    return true;
}

int main() {
    int c;
    int u, v, w;
    cin >> c;

    while (c!=0){
        cin >> n >> m;
        graph.clear();
        dist = vector<int>(MAX, INT_MAX);
        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            graph.push_back(Edge(u, v, w));
        }

        bool res = bellmanFord(0);
        if(!res){
            cout << "possible" << endl;
        } else {
            cout << "not possible" << endl;
        }

        c--;
    }
}