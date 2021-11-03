//spoj
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#define MAX 100000 + 5
using namespace std;


void dfs(int s, vector<bool>&visited, vector<int>graph[], vector<int>&path){
    visited[s] = true;
    stack<int>st;
    st.push(s);
    path[s] = s;

    while(!st.empty()){
        int u = st.top();
        st.pop();

        for(int &v : graph[u]){
            if(!visited[v]){
                visited[v] = true;
                st.push(v);
                path[v] = s;
            }
        }
    }

}

int main() {
    int t, n, e, u , v;
    cin >> t;
    int cnt;

    while(t != 0){
        vector<bool>visited(MAX, false);
        vector<int>graph[MAX];
        vector<int>path(MAX, -1);

        cin >> n >> e;
        for(int i = 0; i < e; i++){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cnt = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, visited, graph, path);
            }
        }

        set<int>st;
        for(int i = 0; i < n; i++){
            st.insert(path[i]);
        }
        cout << st.size() << endl;
        t--;
    }
    return 0;
}

