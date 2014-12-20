#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int INF = 1000;

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
    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; ++i) {
        int c, d, v;
        cin >> c >> d >> v;

        /*flow_network nw(2+c+);

        /*const int START = 0,
                    SINK = 1,
                    CATS = 2,
                    DOGS = 2+c;

        /*for (int j = 0; j < c; ++j) {
            nw.add_edge(START, CATS + j, 1);
        }
        for (int j = 0; j < d; ++j) {
            nw.add_edge(DOGS+j, SINK, 1);
        }*/

        vector<pair<int,int> > catl, dogl;

        for (int j = 0; j < v; ++j) {
            char c1, c2;
            int i1, i2;
            cin >> c1 >> i1 >> c2 >> i2;

            i1++;
            i2++;

            if(c1 == 'C')
                catl.push_back(make_pair(i1, i2));
            else
                dogl.push_back(make_pair(i1, i2));
        }

        for (int k = 0; k < catl.size(); ++k) {
            cout << catl[k].first << ":" << catl[k].second << " ";
        }
        cout << endl;
        for (int l = 0; l < dogl.size(); ++l) {
            cout << dogl[l].first << ":" << dogl[l].second << " ";
        }
        cout << endl;

        flow_network nw(2+v);


    }
}