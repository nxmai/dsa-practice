//uva
#include <iostream>
#include <vector>
#define MAX 20
const int INF = 1e9 + 7;

using namespace std;

void floyd(vector<vector<int>> &dist){
    for(int k = 1; k <= MAX; k++){
        for(int i = 1; i <= MAX; i++){
            for(int j = 1; j <= MAX; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

string formatted(int n) {
    return (n >= 10 ? to_string(n) : " " + to_string(n));
}

int main() {
    int u, v;
    int n;
    int cnt = 1;

    while(true){
        vector<vector<int>>dist(MAX + 1, vector<int>(MAX + 1, INF));

        for(int u = 1; u <= 19; u++){
            if(!(cin >> n)){
                return 0;
            }

            for(int i = 0; i < n; i++){
                cin >> v;
                dist[u][v] = 1;
                dist[v][u] = 1;
            }
        }

        floyd(dist);

        cin >> n;
        cout << "Test Set #" << cnt++ << endl;
        for(int i = 0; i < n; i++){
            cin >> u >> v;
            cout << formatted(u) << " to " << formatted(v) << ": " << dist[u][v] << endl;
        }
        cout << endl;
    }

    return 0;
}