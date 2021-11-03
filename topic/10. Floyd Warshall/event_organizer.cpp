//codechef
#include <iostream>
#include <vector>

using namespace std;
#define MAX 49

vector<vector<int>>graph;
int n;

void floyd(){
    for(int k = 0; k < MAX; k++){
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                if(i <= k && k <= j)
                    graph[i][j] = max(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main() {
    int t, s, e, c;

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        graph = vector<vector<int>>(MAX, vector<int>(MAX, 0));

        for(int i = 0; i < n; i++){
            cin >> s >> e >> c;
            graph[s][e] = max(c, graph[s][e]);
        }
        floyd();

        cout << graph[0][MAX - 1] << endl;
    }

    return 0;
}