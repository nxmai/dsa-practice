#include <iostream>

using namespace std;

#define MAX 30000

int parent[MAX + 5];
int ranks[MAX + 5];
int number[MAX + 5];

void makeSet() {
    for(int i = 1; i <= MAX; i++){
        parent[i] = i;
        ranks[i] = 0;
        number[i] = 1;
    }
}

int findSet(int u){
    if(parent[u] != u){
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

void unionSet(int u, int v){
    int up = findSet(u);
    int vp = findSet(v);

    if(up == vp)
        return;
    if(ranks[up] > ranks[vp]){
        parent[vp] = up;
        number[up] += number[vp];
    }
    else if (ranks[up] < ranks[vp]){
        parent[up] = vp;
        number[vp] += number[up];
    }
    else {
        parent[up] = vp;
        ranks[vp]++;
        number[vp] += number[up];
    }
}

int main() {
    int t, n, m, a, b;
    cin >> t;
    while(t != 0){
        cin >> n >> m;
        makeSet();

        for(int i = 0; i < m; i++){
            cin >> a >> b;
            unionSet(a, b);
        }

        int res = 0;
        for(int i = 1; i <= n; i++){
            if(parent[i] == i && number[i] > res){
                res = number[i];
            }
        }
        cout << res << endl;

        t--;
    }
}