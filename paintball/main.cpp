#include <iostream>
#include <vector>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>

using namespace std;

const int INF = 1000;
const double EPS = 1e-9;

struct edge {
    int u, v, cap;
    edge *rev;
    bool forward;
    edge(int _u, int _v, int _cap, bool forw)
            : u(_u), v(_v), cap(_cap), forward(forw) { }
};

struct flow_network {
    int n;
    vector<vector<edge*> > adj;
    flow_network(int _n) : n(_n), adj(_n) { }

    void add_edge(int u, int v, int cap) {
        edge *e = new edge(u, v, cap, true);
        edge *rev = new edge(v, u, 0, false);
        e->rev = rev;
        rev->rev = e;
        adj[u].push_back(e);
        adj[v].push_back(rev);
    }

    int augment(int s, int t) {
        vector<edge*> back(n, (edge*)0);
        queue<int> Q;
        Q.push(s);
        back[s] = (edge*)1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i]->v;
                if (back[v] == NULL && adj[u][i]->cap > 0) {
                    back[v] = adj[u][i];
                    Q.push(v);
                }
            }
        }

        if (back[t] == NULL)
            return 0;

        stack<edge*> S;
        S.push(back[t]);
        int bneck = back[t]->cap;
        while (S.top()->u != s) {
            S.push(back[S.top()->u]);
            bneck = min(bneck, S.top()->cap);
        }

        while (!S.empty()) {
            S.top()->cap -= bneck;
            S.top()->rev->cap += bneck;
            S.pop();
        }

        return bneck;
    }

    int max_flow(int source, int sink) {
        int flow = 0;
        while (true) {
            int f = augment(source, sink);
            if (f == 0) {
                break;
            }

            flow += f;
        }

        return flow;
    }
};

typedef complex<int> coord;

int main() {
    int n,m;

    cin >> n >> m;

    flow_network nw(2 + n*2); //first is start, last is end

    for (int i = 1; i <= n; ++i) {
        nw.add_edge(0, i, 1);
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        nw.add_edge(a, b+n, 1);
        nw.add_edge(b, a+n, 1);
    }

    for (int i = n+1; i < nw.adj.size()-1; ++i) {
        nw.add_edge(i, nw.adj.size()-1, 1);
    }

    int ans = n - nw.max_flow(0, nw.adj.size()-1);

    vector<int> out;

    for (int i = 1; i < n+1; ++i) {
        for (int j = 0; j < nw.adj[i].size(); ++j) {
            if(nw.adj[i][j]->cap == 0){
                out.push_back(nw.adj[i][j]->v-(n));
            }
            //cout << i << ": " << nw.adj[i][j]->v << " " << nw.adj[i][j]->cap << endl;
        }
    }

    if(ans != 0)
        cout << "Impossible" << endl;
    else {
        for (int i = 0; i < out.size(); ++i) {
            cout << out[i] << endl;
        }
    }
}