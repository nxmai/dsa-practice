//spoj
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <map>
#define MAX 10005

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int>dist(MAX, INT_MAX);

struct option{
    bool operator()(const pair<int,int>&a, const pair<int, int>&b) const {
        return a.second > b.second;
    }
};

void dijkstra(int s){
    priority_queue<pair<int,int>, vector<pair<int, int>>, option> q;
    q.push({s, 0});
    dist[s] = 0;
    
    while(!q.empty()){
        pair<int, int> top = q.top();
        q.pop();
        int u = top.first;
        int w = top.second;

        for(int i = 0; i < graph[u].size(); i++){
            pair<int, int>neighbor = graph[u][i];
            if(w + neighbor.second < dist[neighbor.first]){
                dist[neighbor.first] = w + neighbor.second;
                q.push({neighbor.first, dist[neighbor.first]});
            }
        }
    }
}

int main() {
    int s, n;
    string name, name1, name2;
    int p, nr, cost, u, w, r;

    cin >> s;
    while(s!=0){
        cin >> n;
        graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
        
        map<string, int>city;

        for(int i = 1; i <= n; i++){
            cin >> name;
            city[name] = i;
            cin >> p;
            while(p!=0){
                cin >> u >> w;
                graph[i].push_back({u, w});
                p--;
            }
        }

        cin >> r;
        while(r!=0){
            cin >> name1 >> name2;
          	dist = vector<int>(MAX, INT_MAX);
            dijkstra(city[name1]);
            cout << dist[city[name2]] << endl;

            r--;
        }

        s--;
    }
}
