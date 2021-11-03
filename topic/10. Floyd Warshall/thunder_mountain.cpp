//uva
#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

#define MAX 105
const int INF = 3000;
double dist[MAX][MAX];
int x[MAX];
int y[MAX];

using namespace std;

void floyd(int n){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int t, n, u, v;

    cin >> t;
    for(int h = 1; h <= t; h++){
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = ( i == j ? 0 : INF);
            }
        }

        for(int j = 0; j < n; j++){
            cin >> x[j] >> y[j];
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                double d = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
                if(d <= 10){
                    dist[i][j] = d;
                }
            }
        }

        floyd(n);
        double res = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                res = max(res, dist[i][j]);
            }
        }

        cout << "Case #" << h << ":" <<endl;
        if(res != INF){
            cout << fixed << setprecision(4) << res << endl;
        } else{
            cout << "Send Kurdy" << endl;
        }
        cout << endl;
    }

    return 0;
}