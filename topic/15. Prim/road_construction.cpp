#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

#define MAX 10005
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
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(path[i] == -1){ 
            cnt++;
            continue;
        }

        ans += dist[i];
    }
    if(cnt >=2 )
        return -1;

    return ans;
}

int main(){
    int t, w, u, v;
    string s1, s2;
    cin >> t;

    int cntTest = 1;

    while(t!=0){
        cin >> m;
        map<pair<int, int>, int>cities;
        map<string, int>citiesName;
        pair<int, int>tmp;

        dist = vector<int>(MAX, INF);
        path = vector<int>(MAX, -1);
        visited = vector<bool>(MAX, false);
        vector<pair<int, int>>graph[MAX];

        int cnt = 1;
        for(int i = 0; i < m; i++){
            cin >> s1 >> s2 >> w;
            if(citiesName.find(s1) == citiesName.end()){
                citiesName[s1] = cnt;
                cnt++;
            }
            if(citiesName.find(s2) == citiesName.end()){
                citiesName[s2] = cnt;
                cnt++;
            }

            tmp = {citiesName[s1], citiesName[s2]};
            if(cities.find(tmp) != cities.end()){
                int h = cities[tmp];
                cities[tmp] = min(h, w);
            } else{
                cities[tmp] = w;
            }
        }

        for(map<pair<int, int>, int>::iterator it = cities.begin(); it != cities.end(); it++){
            tmp = it->first;
            u = tmp.first;
            v = tmp.second;
            w = it->second;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }

        n = citiesName.size();
        prim(1, graph);
        int price = mst(graph);
        if(price == -1){
            cout << "Case " << cntTest++ << ": " << "Impossible" << endl;
        } else{
            cout << "Case " << cntTest++ << ": " << price << endl;
        }


        t--;
    }
}
