#include <iostream>
#include <vector>
#include <queue>

#define MAX 1005
const int INF = 1e9;

using namespace std;

int n, m;
vector<int>dist;
vector<int>path;
vector<bool>visited;

struct option{
    bool operator() (const pair<int,int>&a, const pair<int, int>&b) const {
        return a.second > b.second;
    }
};

void prim(int s, vector<pair<int,int>>graph[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, option>pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;

    while(!pq.empty()){
        int u = pq.top().first;
        pq.pop();
        if(visited[u]) continue;

        visited[u] = true;
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if(!visited[v] && dist[v] > w){
                dist[v] = w;
                pq.push(make_pair(v, w));
                path[v] = u;
            }
        }
    }

}

int mst(vector<pair<int,int>>graph[]){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(path[i] == -1) continue;

        ans += dist[i];
    }
    return ans;
}

int main(){
    int t, p, u, v, w;

    cin >> t;
    while(t!=0){
        cin >> p >> n >> m;
        dist = vector<int>(MAX, INF);
        path = vector<int>(MAX, -1);
        visited = vector<bool>(MAX, false);
        vector<pair<int, int>>graph[MAX];

        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }

        prim(1, graph);
        cout << mst(graph) * p << endl;

        t--;
    }

    return 0;
}
