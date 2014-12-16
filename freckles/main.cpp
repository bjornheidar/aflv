#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const double EPS = 1e-9;

struct union_find {
    vector<int> parent;
    union_find(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    // find and union
    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

struct edge {
    int u, v;
    double weight;
    edge(int _u, int _v, double _w) {
        u = _u;
        v = _v;
        weight = _w;
    }
};

bool edge_cmp(const edge &a, const edge &b) {
    return a.weight < b.weight - EPS;
}

vector<edge> mst(int n, vector<edge> edges) {
    union_find uf(n);
    sort(edges.begin(), edges.end(), edge_cmp);
    vector<edge> res;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u,
                v = edges[i].v;
        if (uf.find(u) != uf.find(v)) {
            uf.unite(u, v);
            res.push_back(edges[i]);
        }
    }
    return res;
}

inline double calc_dist(pair<double, double> a, pair<double, double> b) {
    return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}


int main() {
    int test_cases;
    scanf("%d", &test_cases);

    for(int i = 0; i < test_cases; ++i){
        int n;
        scanf("%d", &n);

        vector< pair<double,double> > freckles;

        for (int j = 0; j < n; ++j) {
            double x,y;
            scanf("%lf %lf", &x, &y);

            freckles.push_back(pair<double, double>(x,y));
        }

        vector<edge> edges;
        for (int j = 0; j < freckles.size(); ++j) {
            for (int k = j+1; k < freckles.size(); ++k) {
                if(j != k) {
                    edges.push_back(edge(j, k, calc_dist(freckles[j], freckles[k])));
                }
            }
        }

        vector<edge> tree = mst(n, edges);

        double res = 0.0;
        for (int l = 0; l < tree.size(); ++l) {
            res += tree[l].weight;
        }

        printf("%.2lf\n", res);
    }
}