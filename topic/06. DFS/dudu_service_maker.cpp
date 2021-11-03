//urionline judge
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#define MAX 10000 + 5

using namespace std;

bool dfs(int i, vector<int>graph[], vector<bool>&visited, int n){
    set<int>st;
    stack<int>s;
    s.push(i);
    visited[i] = true;
    st.insert(i);

    while(!s.empty()){
        int u = s.top();
        s.pop();

        for(int&v : graph[u]){
            if(st.find(v) != st.end()){
                return false;
            }

            if(!visited[v]){
                visited[v] = true;
                st.insert(v);
                s.push(v);
            }
        }
    }
    return true;
}

int main() {
    int t, m, n, a, b;
    cin >> t;
    
    while(t != 0){
        cin >> n >> m;
        vector<int>graph[MAX];
        while( m!= 0){
            cin >> a >> b;
            graph[a].push_back(b);
            m--;
        }
        vector<bool>visited(n+1, false);
        bool ans = true;
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                ans = dfs(i, graph, visited, n);
                if(!ans){
                    i = n + 1;
                }
            }
        }

        if(ans)
            cout << "NO" << endl;
        else 
            cout << "YES" << endl;

        t--;
    }
}