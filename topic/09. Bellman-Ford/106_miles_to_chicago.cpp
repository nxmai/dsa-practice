//uri online judge
#include <bits/stdc++.h>
#define MAX 105

using namespace std;

struct Edge{
    int source;
    int target;
    double weight;

    Edge(int source=0, int target=0, double weight=0){
        this->source = source;
        this->target = target;
        this->weight = weight;
    }
};

vector<double>dist;
vector<Edge>graph;
int n, m;

vector<double>prob;
void tut(){
    prob[1] = 1.0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            int u = graph[j].source;
            int v = graph[j].target;
            double w = graph[j].weight;

            prob[u] = max(prob[u], prob[v]*w);
            prob[v] = max(prob[v], prob[u]*w);
        }
    }
}

int main(){
    int u, v, w;
    
    while(cin>>n, n!=0){
        cin>> m;

        dist = vector<double>(MAX, INT_MAX);
        graph.clear();

        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            graph.push_back(Edge(u, v, w*1.0/100));
            //graph.push_back(Edge(v, u, w*1.0/100));
        }

       
        prob = vector<double>(MAX, -1.0);
        tut();
        
        cout << fixed << setprecision(6) << prob[n] * 100 << " percent" << endl;
    }

    return 0;
}
