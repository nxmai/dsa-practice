//codeforces
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000 + 5

using namespace std;

int main() {
    int n, m;
    int t, k;
    int a[MAX];
    vector<int> eds[MAX];

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
       cin >> a[i];
    }

    for(int i = 0; i < n - 1; i++){
        cin >> t >> k;
        eds[t].push_back(k);
        eds[k].push_back(t);
    }

    vector<bool>visited(n + 1, false);
    vector<int>cat(n + 1);
    queue<int>q;
    
    q.push(1);
    cat[1] = (a[1] == 1) ? 1 : 0;
    int cnt = 0;
    visited[1] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int &v : eds[u]){
            if(!visited[v]){
                visited[v] = true;

                if(a[v] == 1){
                    cat[v] = cat[u] + 1;
                }

                if(cat[v] <= m){
                    if(eds[v].size() == 1){
                        cnt++;
                    } else{
                        q.push(v);
                    }
                }
            }
        }
    }

    cout << cnt;
    return 0;
}