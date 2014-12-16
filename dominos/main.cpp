#include <cstdio>
#include <vector>

using namespace std;

vector<int> adj[100000];
vector<bool> visited(100000, false);
vector<int> order;

void topsort(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        topsort(v);
    }
    order.push_back(u);
}

void dfs(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs(v);
    }
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 0; i < test_cases; ++i) {
        int n,m;
        scanf("%d %d", &n, &m);

        //build adj list
        for (int j = 0; j < m; ++j) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a-1].push_back(b-1);
        }

        for (int j = 0; j < n; ++j) {
            topsort(j);
        }

        int components = 0;
        visited.assign(n, false);
        for (vector<int>::reverse_iterator it = order.rbegin(); it != order.rend(); ++it) {
            if(!visited[*it]) {
                dfs(*it);
                components++;
            }
        }

        printf("%d\n", components);

        //reset
        visited.assign(n, false);
        order.clear();
        for (int j = 0; j < n; ++j) {
            adj[j].clear();
        }
    }
}