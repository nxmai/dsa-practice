//timusoj
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

vector<int> adj[500];
int dist[1010];
int visited[1010];

void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s] = 1;

    while(!q.empty()){
        int f = q.front();
        q.pop();

        for(int i = 0; i < adj[f].size(); i++){
            int e = adj[f][i];
            if(!visited[e]){
                visited[e] = 1;
                dist[e] = dist[f] + 1;
                q.push(e);
            }
        }
    }
}

int main() {
    int n, p = 1;
    map<string, int>mp;

    cin >> n;
    for(int i = 0; i < n; i++){
        string f, s, t;
        cin >> f >> s >> t;
        if(!mp[f])
            mp[f]=p++;
        if(!mp[s])
            mp[s]=p++;
        if(!mp[t])
            mp[t]=p++;

        adj[mp[f]].push_back(mp[s]);
        adj[mp[f]].push_back(mp[t]);
        adj[mp[s]].push_back(mp[f]);
        adj[mp[s]].push_back(mp[t]);
        adj[mp[t]].push_back(mp[f]);
        adj[mp[t]].push_back(mp[s]);
    }

    bfs(mp["Isenbaev"]);
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
        if (it->second == 0)
            continue;
            
        if(!visited[it->second])
            cout << it->first << " undefined" << endl;
        else    
            cout << it->first << " " << dist[it->second] << endl;
    }

    return 0;
}
