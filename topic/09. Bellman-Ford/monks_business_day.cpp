//hackerearth
#include <iostream>
#include <vector>
#define MAX 105
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

vector<Edge>graph;
vector<int>dist;
int n, m;

bool checkPositiveCycle(int s){
    int u, v, w;
    dist[s] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;

            if(dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int j = 0; j < m; j++){
        u = graph[j].source;
        v = graph[j].target;
        w = graph[j].weight;

        if(dist[u] != INF && dist[u] + w < dist[v]){
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    int u, v, w;
    cin >> t;

    while(t!=0){
        cin >> n >> m;
        graph.clear();
        dist = vector<int>(MAX, INF);
        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            graph.push_back(Edge(u, v, -w));
        }

        bool res = checkPositiveCycle(1);
        if(res) cout << "Yes" << endl;
        else cout << "No" << endl;

        t--;
    }
}

