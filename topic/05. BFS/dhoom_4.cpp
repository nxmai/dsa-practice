//hackerEarth
#include <iostream>
#include <vector>
#include <queue>

#define MAX 100005
#define MOD 100000

using namespace std;

int a[MAX];
int n;

int bfs (int s, int f){
    vector<int>dist(MAX, -1);
    queue<int>q;
    q.push(s);

    dist[s] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i < n; i++){
            int v = (1LL * a[i] * u) % MOD;

            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);

                if(v == f){
                    return dist[v];
                }
            }
        }
    }
    return -1;
}

int main() {
    int s, f;
    cin >> s >> f >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    cout << bfs(s, f);
}