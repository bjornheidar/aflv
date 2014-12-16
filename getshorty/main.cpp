#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <iomanip>

using namespace std;

const double EPS = 1e-9;

struct edge {
    int u, v;
    double weight;
    edge(int _u, int _v, double _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

vector<edge> adj[10000];
vector<double> dist(10000, -1);

void dijkstra(int start) {
    dist[start] = 1.0;
    priority_queue<pair<double, int>,
    vector<pair<double, int> >,
    less<pair<double, double> > > pq;
    pq.push(make_pair(dist[start], start));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v;
            double w = adj[u][i].weight;
            if (w * dist[u] - EPS > dist[v]) {
                dist[v] = w * dist[u];
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(4);
    int n, m;
    while(true) {
        cin >> n >> m;
        if(n == 0)
            break;
        for (int i = 0; i < m; ++i) {
            int x, y;
            double ratio;

            cin >> x >> y >> ratio;

            adj[x].push_back(edge(x, y, ratio));
            adj[y].push_back(edge(y, x, ratio));
        }

        dijkstra(0);

        cout << dist[n-1] << endl;

        dist.assign(n, -1);
        for (int i = 0; i <n; ++i) {
            adj[i].clear();
        }
    }
}