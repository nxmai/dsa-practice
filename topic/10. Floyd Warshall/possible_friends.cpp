//spoj
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 55
const int INF = 1e9 + 7;

int n;
vector<vector<int>> dist;
string graph[MAX];

void floyd(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            // if(dist[i][k] == INF) continue;
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int t;
    string s;

    cin >> t;
    while(t!=0){
        cin >> s;
        n = s.length();
        dist = vector<vector<int>>(MAX, vector<int>(MAX));
        for(int i = 0; i < n; i++){
            if(i == 0){
                graph[0] = s;
            } else {
                cin >> s;
                graph[i] = s;
            }
            
            for(int j = 0; j < n; j++){
                //cout << graph[i][j] << " ";
                if(graph[i][j] == 'Y'){
                    dist[i][j] = 1;
                } else {
                    dist[i][j] = (i == j ? 0 : INF);
                }
            }
        }

        floyd();

        int cntFr = 0, index;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j] == 2)
                    cnt++;
            }
            if(cnt > cntFr){
                cntFr = cnt;
                index = i;
            }
        }

        cout << index << " " << cntFr << endl;

        t--;
    }
}
