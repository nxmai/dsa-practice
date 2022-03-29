#include <iostream>
#include <string>
#include <set>

using namespace std;

#define MAX 30

int parent[MAX + 5];
int ranks[MAX + 5];

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
    int t, n, a, b;
    char v;
    string c;

    cin >> t;
    while(t != 0){
        cin >> v;
        n = v - 'A';
        makeSet();
      	cin.ignore();

        while(getline(cin, c) && c!= ""){
            a = c[0] - 'A';
            b = c[1] - 'A';
            unionSet(a, b);
        }

        set<int>s;
        for(int i = 0; i <= n; i++){
            s.insert(findSet(i));
        }
        cout << s.size() << endl;
        if(t!=1){
            cout << endl;
        }

        t--;
    }
}