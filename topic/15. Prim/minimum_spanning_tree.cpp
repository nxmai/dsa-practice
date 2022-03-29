#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#define MAX 10005

const int INF = 1e9;

using namespace std;

vector<pair<int, int>>graph[MAX];
vector<int>dist(MAX, INF);
vector<int>path(MAX, -1);
vector<bool>visited(MAX, false);
int n, m;

struct option{
    bool operator() (const pair<int, int> &a, const pair<int, int>&b) const {
        return a.second > b.second;
    }
};

void prims(int s){
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
    while(!pq.empty()){
        int u = pq.top().first;
        pq.pop();
        if(visited[u])
            continue;

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

long long MST(){
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        if(path[i] == -1)
            continue;
        ans += dist[i];
    }
    return ans;
}

int main(){
    
    cin >> n >> m;
    int u, v, w;

    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    int s = 1;
    prims(s);

    cout << MST();

    return 0;
}