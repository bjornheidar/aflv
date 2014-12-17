// Author: Bertel Benóný Bertelsson

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vi adj[100000];
stack<int> order;
vb visited;

int cnt = 0;

int dfs(int u) {
    if (visited[u]) return 0;
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs(v);
    }
    return 1;
}

void topsort(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        topsort(v);
    }
    order.push(u);
}

int main()
{
    int T;
    scanf("%d\n", &T);

    while (T--) {
        int n, m;
        scanf("%d %d\n", &n, &m);

        adj[n] = vi();
        visited = vb(n, false);
        order = stack<int>();
        cnt = 0;

        while (m--) {
            int a, b;
            scanf("%d %d\n", &a, &b);
            adj[--a].push_back(--b);
        }

        for (int u = 0; u < n; u++)
            topsort(u);

        visited = vb(n, false);

        while(!order.empty()) {
            int u = order.top();
            order.pop();
            cnt += dfs(u);
        }

        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        printf("%d\n", cnt);
    }
    return 0;
}
