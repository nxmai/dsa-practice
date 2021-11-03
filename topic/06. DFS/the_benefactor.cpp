//spoj
#include <iostream>
#include <vector>
#include <map>
#define MAX 50000+5
using namespace std;

vector<int>visited(MAX, false);
vector<vector<pair<int, int>>>graph;
int ans;
int maxId;

void dfs(int u, int len){
    if(ans < len){
        ans = len; maxId = u;
    }

    for(auto v : graph[u]){
        if(!visited[v.first]){
            visited[u] = true;
            dfs(v.first, len + v.second);
        }
    }
}

int main() {
    int t;
    int n, u, v, l;

    cin >> t;
    while(t!=0){
        cin >> n;
        visited.assign(MAX, false);
        graph = vector<vector<pair<int, int>>>(n + 1);

        for(int i = 0; i < n-1; i++){
            cin >> u >> v >> l;
            graph[u].push_back({v, l});
            graph[v].push_back({u, l});
        }

        ans = 0;
        maxId = 0;
        for(int i = 1; i <= n; i++){
            if(graph[i].size() == 1){
                dfs(i, 0);
                break;
            }
        }
        
        int max_index = maxId;

        visited.assign(MAX, false);
        ans = 0;

        dfs(max_index, 0);
        
        cout << ans << endl;

        t--;
    }

    return 0;
}