#include <bits/stdc++.h>

using namespace std;
struct cvor{
    int v,w;
};
int V, E;
int v, u, w;
vector<cvor> graph[1000];
vector<int> dist(100,100000000);

int main()
{
    cin >> V >> E;
    for (int i=0;i<E;i++){
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    dist[0] = 0;
    for (int i=0;i<V-1;i++){
        for (int u=0;u<V;u++){
            for (int j=0;j<graph[u].size();j++){
                v = graph[u][j].v; w = graph[u][j].w;
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }
    for (int i=0;i<V;i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}
