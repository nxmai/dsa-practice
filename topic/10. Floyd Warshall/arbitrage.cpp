//uva
#include <iostream>
#include <vector>
#include <map>

#define MAX 32

using namespace std;

int n;

void floyd(vector<vector<double>> &dist){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][j] < dist[i][k] * dist[k][j]){
                    dist[i][j] = dist[i][k] * dist[k][j];
                }
            }
        }
    }
}

int main() {
    int m;
    double w;
    string s, u, v;
    int cnt = 1;

    while(1){
        cin >> n;
        if(n == 0)
            break;
        map<string, int>currency;
        vector<vector<double>>dist = vector<vector<double>>(MAX, vector<double>(MAX));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = 0;
                if(i == j){
                    dist[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            cin >> s;
            currency[s] = i;
        }

        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> u >> w >> v;
            dist[currency[u]][currency[v]] = w;
        }

        floyd(dist);
        bool res = false;
        for(int i = 0; i < n; i++){
            if(dist[i][i] > 1){
                res = true;
                break;
            }
        }
        cout << "Case " << cnt++ <<": " << (res ? "Yes" : "No") << endl;

    }
    return 0;
}