#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <math.h>
#include <iomanip>

#define MAX 800

const int INF = 1e9;

using namespace std;

vector<double>dist;
vector<int>path;
vector<bool>visited;
int n, m;

struct option{
    bool operator() (const pair<int, double> &a, const pair<int, double>&b) const {
        return a.second > b.second;
    }
};

void prims(int s, double graph[MAX][MAX]){
    priority_queue<pair<int, double>, vector<pair<int, double>>, option> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;

    while(!pq.empty()){
        int u = pq.top().first;
        pq.pop();
        if(visited[u])
            continue;

        visited[u] = true;
        for(int i = 0; i < n; i++){
            int v = i;
            double w = graph[u][i];
            if(!visited[v] && dist[v] > w){
                dist[v] = w;
                pq.push(make_pair(v, w));
                path[v] = u;
            }
        }
    }
}

double MST(){
    double ans = 0;
    for(int i = 0; i < n; i++){
        if(path[i] == -1)
            continue;
        ans += dist[i];
    }
    return ans;
}

int main(){
    
    int x, y, u, v;
    double w;

    while(true){
        if(!(cin >> n)){
            return 0;
        }
        
        vector<pair<int, int>>points;
        double graph[MAX][MAX];
        dist = vector<double>(MAX, INF);
        visited = vector<bool>(MAX, false);
        path = vector<int>(MAX, -1);

        for(int i = 0; i < n; i++){
            cin >> x >> y;
            points.push_back(make_pair(x, y));
        }

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                w = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
                graph[i][j] = graph[j][i] = w;
            }
        }

        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> u >> v;
          	u--; v--;
            graph[u][v] = graph[v][u] = 0;
        }

        int s = 0;
        prims(s, graph);

        cout << fixed << setprecision(2) << MST() << endl;
    }
    

    return 0;
}