//hackerearth
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define MAX 1005

using namespace std;

vector<int> graph[MAX];
vector<int> dist(MAX, -1);
vector<bool> visited(MAX, false);
// vector<int> girl(MAX, -1);



void recur(int s){
    visited[s] = true;

    for(int &v : graph[s]){
        if(!visited[v]){
            dist[v] = dist[s] + 1;
            recur(v);
        }
    }
}

int main() {
    int n, u ,v;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int min_dist = MAX;
    int min_id = MAX;
    
    dist[1] = 0;
    recur(1);


    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> u;
        if((dist[u] < min_dist ) || (dist[u] == min_dist && u < min_id)){
            min_dist = dist[u];
            min_id = u; 
        }
    }
    cout << min_id;

    return 0;


}