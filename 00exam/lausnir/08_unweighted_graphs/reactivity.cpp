// Author: Bertel Benóný Bertelsson

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vi adj[1010], order;
vb visited;

int cnt = 0;
bool valid = true;

void topsort(int u) {
    if (visited[u]) return;

    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        topsort(v);
    }
    order.push_back(u);
}

int main()
{
    int N, K;
    while (scanf("%d %d\n", &N, &K) != EOF) {

        visited = vb(N, false);
        adj[N] = vi();
        order = vi();
        valid = true;

        for (int i = 0; i < K; ++i) {
            int a, b;
            scanf("%d %d\n", &a, &b);
            adj[a].push_back(b);
        }

        for (int u = 0; u < N; ++u) {
            topsort(u);
        }

        for (int i = 0; i < order.size(); ++i) {
            int u = order[i];
            if (i != order.size() - 1) {
                int v = order[i + 1];
                if (find(adj[v].begin(), adj[v].end(), u) == adj[v].end()) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            for (int i = order.size() - 1; i >= 0; --i) {
                if (i != 0) printf("%d ", order[i]);
                else        printf("%d\n", order[i]);
            }
        } else printf("back to the lab\n");

        for (int i = 0; i < N; ++i) {
            adj[i].clear();
        }
    }
    return 0;
}
