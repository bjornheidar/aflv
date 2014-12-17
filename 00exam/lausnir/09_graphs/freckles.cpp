// Author: Sævar Örn Kjartansson

#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct union_find {
    
    vector<int> parent;

    union_find(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u) { return (u == parent[u]) ? u : parent[u] = find(parent[u]); }
    void unite(int u, int v) { parent[find(u)] = find(v); }
};

struct edge {
    
    int u, v;
    double len;
    edge(int u, int v, double len)
        : u(u), v(v), len(len) {}
};

bool cmp_edge(edge e1, edge e2) {
    return e1.len < e2.len;
}

int main() {

    int T;

    scanf("%d\n", &T);

    for (int t = 0; t < T; t++) {
        
        int N;
        scanf("%d\n", &N);

        vector<pair<double, double> > points;
        vector<edge> edges;
        
        for (int i = 0; i < N; i++) {
            double x, y;
            scanf("%lf %lf\n", &x, &y);
            points.push_back(make_pair(x,y));
        }

        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                double dx = points[i].first  - points[j].first;
                double dy = points[i].second - points[j].second;
                double len = sqrt(dx*dx + dy*dy);
                edges.push_back(edge(i, j, len));
            }
        }
        
        sort(edges.begin(), edges.end(), cmp_edge);

        double sum = 0;
        union_find uf(N);

        for (int i = 0; i < edges.size(); i++) {
            edge e = edges[i];
            if (uf.find(e.u) == uf.find(e.v))
                continue;

            uf.unite(e.u, e.v);
            sum += e.len;
        }

        printf("%.2f\n", sum);
    }
}
