//spoj
#include <iostream>
#include <vector>
#include <map>
#define MAX 10000 + 5

using namespace std;

vector<int>graph[MAX];
int n, m;
vector<bool>visited;

void dfs(int u, int & cnt){
    visited[u] = true;
    cnt++;

    for(int&v : graph[u]){
        if(!visited[v]){
            dfs(v, cnt);
        }
    }
}

int main() {
    cin >> n >> m;
    int u, v;

    while(m!=0){
        cin >> u >> v;
        graph[u].push_back(v);

        m--;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        visited.assign(n+1, false);
        int cnt = 0;
        dfs(i, cnt);
        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}