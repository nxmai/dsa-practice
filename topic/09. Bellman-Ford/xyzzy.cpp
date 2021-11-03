//uva
#include <iostream>
#include <vector>
#include <queue>

#define MAX 105
const int INF = 1e9 + 7;

using namespace std;

int n, m;
bool visited[MAX];
int dist[MAX], energy[MAX];
vector<pair<int, int>> graph;

bool hasPathBFS(int s, int f){
    fill(visited, visited + n + 1, false);
    queue<int>q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(pair<int, int> &edge : graph){
            if(edge.first == u){
                int v = edge.second;

                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);

                    if(v == f){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool bellman(int s, int f){
    fill(dist, dist + n + 1, -INF);
    dist[s] = 100;

    for(int i = 0; i < n-1; i++){
        for(pair<int, int> &edge : graph){
            int u = edge.first;
            int v = edge.second;
            if(dist[u] > 0){
                dist[v] = max(dist[v], dist[u] + energy[v]);
            }
        }
    }

    for(pair<int, int> &edge : graph){
        int u = edge.first;
        int v = edge.second;

        if(dist[u] > 0 && dist[u] + energy[v] > dist[v] && hasPathBFS(u, f))
            return true;
    }

    return dist[f] > 0;
}

int main() {
    int v;
    while(cin >> n, n!=-1){
        graph.clear();
        for(int i = 1; i <= n; i++){
            cin >> energy[i] >> m;

            for(int j = 0; j < m; j++){
                cin >> v;
                graph.push_back(make_pair(i, v));
            }
        }

        bool canGo = bellman(1, n);
        cout << (canGo ? "winnable" : "hopeless") << endl;
    }

    return 0;
}