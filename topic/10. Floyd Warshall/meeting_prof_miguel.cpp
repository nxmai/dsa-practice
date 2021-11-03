//uva
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 28
const int INF = 1e9 + 7;

using namespace std;

struct Place{
    int id, cost;

    bool operator<(const Place &other) const {
        return cost < other.cost || (cost == other.cost && id < other.id);
    }
};

void floyd(vector<vector<int>> &dist){
    for(int k = 0; k < MAX; k++){
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int n;
    char c1, c2, c3, c4;
    int w, u, v;

    while(cin >> n, n!=0){
        vector<vector<int>>distY(MAX, vector<int>(MAX));
        vector<vector<int>>distM(MAX, vector<int>(MAX));

        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                distY[i][j] = (i == j ? 0 : INF);
                distM[i][j] = (i == j ? 0 : INF);
            }
        }

        for(int i = 0; i < n; i++){
            cin >> c1 >> c2 >> c3 >> c4;
            cin >> w;

            u = c3 - 'A';
            v = c4 - 'A';
            //cout << c1 << " " << c2 << " " << c3 << " " << c4 << " " << u << " " << v <<endl;
            if(c1 == 'Y'){
                distY[u][v] = min(distY[u][v], w);
                if(c2 == 'B'){
                    distY[v][u] = min(distY[v][u], w);
                }
            } else {
                distM[u][v] = min(distM[u][v], w);
                if(c2 == 'B'){
                    distM[v][u] = min(distM[v][u], w);
                }
            }
        }

        floyd(distY);
        floyd(distM);

        cin >> c3 >> c4;
        int x = c3 - 'A';
        int y = c4 - 'A';

        vector<Place>res;
        int minD = INF;
        for(int i = 0; i < MAX; i++){
            int dist1 = distY[x][i];
            int dist2 = distM[y][i];
            // cout << dist1 << "  " << dist2 << endl;
            if(dist1 != INF && dist2 != INF && dist1 + dist2 <= minD){
                res.push_back({i, dist1 + dist2});
                minD = dist1 + dist2;
            }
        }

        if(res.empty()){
            cout << "You will never meet.";
        } else{
            cout << minD;
            sort(res.begin(), res.end());

            for(Place &place : res){
                if(place.cost == minD){
                    cout << " " << char(place.id + 'A');
                }
            }
        }
        cout << endl;
    }

    return 0;
}
