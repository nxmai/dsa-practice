//codeforces
#include <iostream>
#include <vector>

#define MAX 505

using namespace std;

int main() {
    int u, v;
    int n;
    int dist[MAX][MAX];
    long long res[MAX];
    int mid[MAX];

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> dist[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        cin >> mid[i];
    }

    for(int id = n; id >= 1; id--){
        int k = mid[id];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }

        for(int i = id; i <= n; i++){
            u = mid[i];
            for(int j = id; j <= n; j++){
                v = mid[j];
                res[id] += dist[u][v];
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }

    return 0;
}