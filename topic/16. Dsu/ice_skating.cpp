#include <iostream>
#include <vector>
#include <set>

#define MAX 105

int parent[MAX + 5];
int ranks[MAX + 5];

using namespace std;

void makeSet() {
    for(int i = 0; i <= MAX; i++){
        parent[i] = i;
        ranks[i] = 0;
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
    }
    else if (ranks[up] < ranks[vp]){
        parent[up] = vp;
    }
    else {
        parent[up] = vp;
        ranks[vp]++;
    }
}

int main() {
    int n, x, y;
    cin >> n;

    vector<int>vx, vy;

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        vx.push_back(x);
        vy.push_back(y);
    }

    makeSet();
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(vx[i] == vx[j] || vy[i] == vy[j]){
                unionSet(i, j);
            }
        }
    }

    set<int>s;
    for(int k = 0; k < n; k++){
        s.insert(findSet(k));
    }
    cout << s.size() - 1 << endl;

    return 0;
}