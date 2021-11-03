//spoj
#include <iostream>
#include <vector>
#define MAX 105
const long long INF = (1LL << 30) * 100 + 7;

using namespace std;

struct Edge{
    int source;
    int target;
    long long weight;
};

int n;
long long dist[MAX][MAX];
vector<Edge>graph;
string places[MAX];

void bellman(int s){
    int u, v;
    long long w;
    dist[s][s] = 0;

    for(int i = 1; i <= n-1; i++){
        for(Edge edge:graph){
            u = edge.source;
            v = edge.target;
            w = edge.weight;

            if(dist[s][u] != INF && (dist[s][u] + w < dist[s][v])){
                dist[s][v] = dist[s][u] + w;
            }
        }
    }

    for(int j = 0; j < n - 1; j++){
        for(Edge edge:graph){
            u = edge.source;
            v = edge.target;
            w = edge.weight;

            if(dist[s][u] != INF && (dist[s][u] + w < dist[s][v])){
                dist[s][v] = -INF;
            }
        }
    }
}

int main() {
    int w, q, tc = 1, u, v;
    
    while(cin >> n, n!=0){
        graph.clear();

        for(int i = 0; i < n; i++){
            cin >> places[i];
            for(int j = 0; j < n; j++){
                cin >> w;
                dist[i][j] = INF;
                if(i!=j && w==0)
                    continue;
                if(i==j && w>=0)
                    w=0;
                graph.push_back((Edge){i, j, w});
            }
        }
        for(int i = 0; i < n; i++){
            bellman(i);
        }

        cin >> q;
        cout << "Case #" << tc++ << ":" <<endl;
        for(int i = 0; i < q; i++){
            cin >> u >> v;
            if(dist[u][v] == -INF)
                cout << "NEGATIVE CYCLE" << endl;
            else if(dist[u][v] == INF)
                cout << places[u] <<"-" << places[v] << " NOT REACHABLE" << endl;
            else 
                cout << places[u] <<"-" << places[v] << " " << dist[u][v] << endl;
        }
    
    }

    return 0;
}
