//uva
#include <iostream>
#include <vector>

#define MAX 85
const int INF = 1e9 + 7;

using namespace std;

vector<vector<int>>graph;
vector<vector<int>>maxPrices;
int c;

void floyd(){
    for(int k = 1; k <= c; k++){
        for(int i = 1; i <= c; i++){
            for(int j = 1; j <= c; j++){
                int maxP = max(maxPrices[i][k], maxPrices[k][j]);
                if(graph[i][j] + maxPrices[i][j] > graph[i][k] + graph[k][j] + maxP){
                    graph[i][j] = graph[i][k] + graph[k][j];
                    maxPrices[i][j] = maxP;
                }
                
            }
        }
    }

    for(int k = 1; k <= c; k++){
        for(int i = 1; i <= c; i++){
            for(int j = 1; j <= c; j++){
                int maxP = max(maxPrices[i][k], maxPrices[k][j]);
                if(graph[i][j] + maxPrices[i][j] > graph[i][k] + graph[k][j] + maxP){
                    graph[i][j] = graph[i][k] + graph[k][j];
                    maxPrices[i][j] = maxP;
                }
                
            }
        }
    }
}

int main() {
    int r, q;
    int u, v, w;
    int cnt = 1;

    while(cin >> c >> r >> q, c!=0 && r!=0 && q!=0){
        graph = vector<vector<int>>(MAX, vector<int>(MAX));
        maxPrices = vector<vector<int>>(MAX, vector<int>(MAX));

        int f[MAX];
        for(int i = 1; i <= c; i++){
            cin >> f[i];
        }

        for(int i = 1; i <= c; i++){
            for(int j = 1; j <= c; j++){
                graph[i][j] = INF;
                maxPrices[i][j] = max(f[i], f[j]);
            }
        }

        for(int i = 0; i < r; i++){
            cin >> u >> v >> w;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        floyd();

        cout << "Case #" << cnt++ <<endl;
        for(int i = 0; i < q; i++){
            cin >> u >> v;
            cout << (graph[u][v] == INF ? -1 : graph[u][v] + maxPrices[u][v]) << endl;
        }
        cout << endl;
    }

    return 0;
}