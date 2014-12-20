#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

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

int main() {
    ios_base::sync_with_stdio(false);

    int n, m, s, t;

    cin >> n >> m >> s >> t;

    flow_network nw(n);

    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        nw.add_edge(u, v, c);
    }

    int f = nw.max_flow(s, t);

    vector<edge> used;
    for (int i = 0; i < nw.adj.size(); ++i) {
        for (int j = 0; j < nw.adj[i].size(); ++j) {
            if(nw.adj[i][j]->forward && nw.adj[i][j]->rev->cap != 0){
                edge e = *nw.adj[i][j];
                used.push_back(e);
            }
        }
    }

    cout << n << " " << f << " " << used.size() << endl;
    for (int k = 0; k < used.size(); ++k) {
        cout << used[k].u << " " << used[k].v << " " << used[k].rev->cap  << endl;
    }

    return 0;
}
