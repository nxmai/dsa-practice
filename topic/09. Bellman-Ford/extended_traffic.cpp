//lightoj
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#define MAX 205
const int INF = 1e9 + 7;

using namespace std;

struct Edge
{
    int source;
    int target;
    int weight;

    Edge(int source = 0, int target = 0, int weight = 0)
    {
        this->source = source;
        this->target = target;
        this->weight = weight;
    }
};

int n, m;
vector<int> dist;
vector<Edge> graph;

void bellmanFord(int s)
{
    int u, v, w;
    dist[s] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;

            if ((dist[u] != INF) && (dist[u] + w < dist[v]))
            {
                dist[v] = dist[u] + w;
            }
        }
    }

        for (int j = 0; j < m; j++)
        {
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;

            if ((dist[u] != INF) && (dist[u] + w < dist[v]))
                dist[v] = -INF;
        }
    
    
}

int main()
{
    int t, busy;
    int u, v, w;
    int q, target;
    vector<int> busyness;

    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        cin.ignore();
        cin >> n;
        busyness = vector<int>(n + 1);
        dist = vector<int>(MAX, INF);
        graph.clear();

        for (int i = 1; i <= n; i++)
        {
            cin >> busy;
            busyness[i] = busy;
        }

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            w = pow(busyness[v] - busyness[u], 3);
            graph.push_back(Edge(u, v, w));
        }

        cin >> q;
        cout << "Case " << j << ":" << endl;
        bellmanFord(1);
        for (int i = 0; i < q; i++)
        {
            cin >> target;

            if (dist[target] >= 3 && dist[target] != INF)
            {
                cout << dist[target] << endl;
            }
            else
            {
                cout << "?" << endl;
            }
        }
    }
}
