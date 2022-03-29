#include <iostream>
#include <vector>
#include <map>

#define MAX 100001

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
    int n, a, b;
    map<int, int>mp;
    int p[MAX];
    int maxP = 0;

    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        mp[p[i]] = i;
        maxP = max(maxP, p[i]);
    }
    if(maxP > max(a, b)){
        cout << "NO";
        return 0;
    }
    
    makeSet();
    for(int i = 1; i <= n; i++){
        if(mp[a-p[i]]){
            unionSet(i, mp[a-p[i]]);
        } else{
            unionSet(i, n+1);
        }

        if(mp[b-p[i]]){
            unionSet(i, mp[b-p[i]]);
        } else{
            unionSet(i, 0);
        }
    }

    a = findSet(0);
    b = findSet(n+1);

    if(a != b){
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++){
            if(i!=1)
                cout << " ";
            if(findSet(i) == a)
                cout << "0";
            else
                cout << "1";
        }
    }else{
        cout << "NO";
    }
    return 0;
}