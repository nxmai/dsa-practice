#include <iostream>
#include <vector>
#include <set>
#include <sstream>

#define MAX 105

using namespace std;

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
    vector<set<int>>vt(MAX);
    int n, p, t, i, j;
  	string s;

    cin >> n;
    
    while(n!=0){
        vt = vector<set<int>>(MAX);
        cin >> p >> t;
      	cin.ignore();
         while(getline(cin, s) && s!=""){
            stringstream ss;
            ss << s;
            ss >> i >> j;
            vt[i].insert(j);
        }

        makeSet();
        for(int k = 1; k <= p -1; k++){
            for(int h = k+1; h <= p; h++){
                if(vt[k] == vt[h]){
                    unionSet(k, h);
                }
            }
        }

        set<int>s;
        for(int k = 1; k <= p; k++){
            s.insert(findSet(k));
        }
        cout << s.size() << endl;
      
      if(n!=1){
            cout << endl;
        }

        n--;
    }

    return 0;
}