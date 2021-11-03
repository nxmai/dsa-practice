//spoj
#include <iostream>
#include <vector>
#define MAX 105

using namespace std;

vector<vector<char>>graph;
vector<vector<bool>>visited;
vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
char array[] = "ALLIZZWELL";
bool ans = false;
int r, c;

void dfs(int i, int j, int cur){
    if(cur == 9){
        ans = true;
        return;
    }

    for(auto dir : dirs){
        int u = i + dir[0];
        int v = j + dir[1];

        if(u>=0 && u<r && v>=0 && v<c && !visited[u][v] && graph[u][v] == array[cur+1]){
            visited[u][v] = true;
            dfs(u, v, cur+1);
            visited[u][v] = false;
        }
    }
}

int main() {
    int t;
    char a;
    cin >> t;
    

    while(t!=0){
        cin >> r >> c;
        graph.clear();
        for(int i = 0; i < r; i++){
            vector<char>tmp;
            for(int j = 0; j < c; j++){
                cin >> a;
                tmp.push_back(a);
            }
            graph.push_back(tmp);
        }

        visited.assign(MAX, vector<bool>(MAX, false));
        ans = false;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(graph[i][j] == 'A'){
                    visited[i][j] = true;
                    dfs(i, j, 0);
                    visited[i][j] = false;
                }
            }
            if(ans) break;
        }

        (ans) ? cout << "YES" << endl : cout << "NO" <<endl;

        t--;
    }

    return 0;
}