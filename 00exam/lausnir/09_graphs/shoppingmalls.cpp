// Author: Carl Andreas

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <limits>

using namespace std;

struct edge {
    int u, v, f;
    double weight;
    edge(int _u, int _v, double _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

struct vertex {
    int x, y, f;
    vertex(int _x, int _y, int _f)
    {
        x = _x;
        y = _y;
        f = _f;
    }
};

bool edge_cmp(const edge &a, const edge &b) {
    return a.weight < b.weight;
}

int INF = std::numeric_limits<int>::max();

vector<edge> adj[200];
vector<double> dist(200, INF);
vector<int> path(200);

void dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<double, int>,
    vector<pair<double, int> >,
    greater<pair<double, int> > > pq;
    pq.push(make_pair(dist[start], start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (unsigned int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v;
            double w = adj[u][i].weight;
                if (w + dist[u] < dist[v]) {
                path[v] = u;
                dist[v] = w + dist[u];
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}



int main()
{
    int n , m, f, x, y, Q;
    string method;
    vector<vertex> vert;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> f >> x >> y;
        vert.push_back(vertex(x, y, f));
    }
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y >> method;
        if(method == "walking")
        {
            adj[x].push_back(edge(x , y, hypot(abs(vert[x].x - vert[y].x),abs(vert[x].y - vert[y].y))));
            adj[y].push_back(edge(y , x, hypot(abs(vert[y].x - vert[x].x),abs(vert[y].y - vert[x].y))));
        }
        else if(method == "stairs")
        {
            adj[x].push_back(edge(x , y, sqrt(pow(abs(vert[x].x - vert[y].x), 2.0) + pow(abs(vert[x].y - vert[y].y), 2.0) + pow((abs(vert[x].f - vert[y].f) * 5), 2.0) )));
            adj[y].push_back(edge(y , x, sqrt(pow(abs(vert[x].x - vert[y].x), 2.0) + pow(abs(vert[x].y - vert[y].y), 2.0) + pow((abs(vert[x].f - vert[y].f) * 5), 2.0) )));
        }
        else if(method == "escalator")
        {
            adj[x].push_back(edge(x , y, 1.0 ));
            adj[y].push_back(edge(y , x, sqrt(pow(abs(vert[x].x - vert[y].x), 2.0) + pow(abs(vert[x].y - vert[y].y), 2.0) + pow((abs(vert[x].f - vert[y].f) * 5), 2.0) ) * 3));
        }
        else
        {
            adj[x].push_back(edge(x , y, 1.0 ));
            adj[y].push_back(edge(y , x, 1.0 ));
        }
    }

    cin >> Q;

    for(int i = 0; i < Q; i++)
    {
        vector<int> leid;
        cin >> x >> y;
        dijkstra(x);
        for(int j = 0; j < path.size(); j++)
        {
            leid.push_back(y);
            y = path[y];
            if(y == x)
            {
                leid.push_back(y);
                break;
            }
        }

        for(int k = leid.size() - 1; k >= 0; k--)
        {
            cout << leid[k] << " ";
        }
        cout << endl;

        dist.assign(200, INF);
    }


    return 0;
}
