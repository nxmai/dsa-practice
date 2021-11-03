//uva
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

int n;
vector<Edge>graph;
vector<int>dist(MAX, INF);

void bellman(int s){
    int u, v, w;
    dist[s] = 0;

    for(int i = 0; i < n-1; i++){
        for(Edge ed: graph){
            u = ed.source;
            v = ed.target;
            w = ed.weight;

            dist[v] = min(dist[v], dist[u] + w);
        }
    }
}

int main() {
    cin >> n;
    string w;
    
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            cin >> w;

            if(w != "x"){
                int k = atoi(w.c_str());
                graph.push_back(Edge(i, j, k));
                graph.push_back(Edge(j, i, k));
            }
        }
    }

    bellman(1);
    int res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, dist[i]);
    }
    cout << res;

    return 0;
}