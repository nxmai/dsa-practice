#include <iostream>
#include <vector>
#include <set>
#include <queue>

#define MAX 100005

int parent[MAX + 5];
int ranks[MAX + 5];
int number[MAX + 5];

using namespace std;

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

pair<int,int> unionSet(int u, int v){
    int up = findSet(u);
    int vp = findSet(v);

    if(up == vp)
        return {number[up], up};
    if(ranks[up] > ranks[vp]){
        parent[vp] = up;
        number[up] += number[vp];
        return {number[up], up};    
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
    return {number[vp], vp};
}

int main() {
    int n, q;
    int a, b;
    int up, vp;
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq; 

    cin >> n >> q;

    makeSet();

    for(int i = 1; i <= n; i++){
        pq.push(make_pair(1, i));
    }

    int maxi = 1;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        pair<int, int> p = unionSet(a, b);
        maxi = max(maxi, p.first);
        pq.push(p);
        while(true){
            pair<int, int>tmp = pq.top();
            int r = findSet(tmp.second);
            if(r != tmp.second){
                pq.pop();
                continue;
            }

            if(number[r] != tmp.first){
                pq.pop();
                continue;
            }
            break;
        }
        cout << maxi - pq.top().first << endl;
    }

    return 0;
}