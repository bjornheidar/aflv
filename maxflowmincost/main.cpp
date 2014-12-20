#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

struct edge {
    int u, v, cap, cost;
    edge *rev;
    bool forward;
    edge(int _u, int _v, int _cap, bool forw)
            : u(_u), v(_v), cap(_cap), forward(forw) { }
};

struct flow_network {
    int n;
    vector<vector<edge*> > adj;
    flow_network(int _n) : n(_n), adj(_n) { }

    void add_edge(int u, int v, int cap, int cost) {
        edge *e = new edge(u, v, cap, true);
        edge *rev = new edge(v, u, 0, false);
        e->cost = cost;
        rev->cost = cost;
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

int main() {
    ios_base::sync_with_stdio(false);

    int n, m, s, t;

    cin >> n >> m >> s >> t;

    flow_network nw(n);

    for (int i = 0; i < m; ++i) {
        int u, v, c, cost;
        cin >> u >> v >> c >> cost;
        nw.add_edge(u, v, c, cost);
    }

    int f = nw.max_flow(s, t);

    int thecost = 0;
    for (int i = 0; i < nw.adj.size(); ++i) {
        for (int j = 0; j < nw.adj[i].size(); ++j) {
            if(nw.adj[i][j]->forward && nw.adj[i][j]->cap == 0){
                edge e = *nw.adj[i][j];
                thecost += e.rev->cost * e.rev->cap;
                cout << e.u << " " << e.v << " " << e.cost << " " << e.cap << endl;
            }
        }
    }

    cout << f << " " << thecost << endl;

    return 0;
}
