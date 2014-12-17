// Author: Björn Heiðar Rúnarsson

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[10001];
vector<bool> fallen(10001, 0);

int knock_over(int u) {
    //if already knocked over
    if (fallen[u]) {
        return 0;
    }

    fallen[u] = true;
    int knocked = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        knocked += knock_over(v);
    }
    return knocked;
}

int main() {
    ios_base::sync_with_stdio(false);

    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; ++i) {
        int n, m, l;
        cin >> n >> m >> l;

        //init
        fallen.assign(n+1, 0);
        for (int j = 0; j < n+1; ++j) {
            adj[j].clear();
        }

        //Build adjacency list
        for (int j = 0; j < m; ++j) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }

        //knock over the z tile
        int ans = 0;
        for (int j = 0; j < l; ++j) {
            int z;
            cin >> z;
            ans += knock_over(z);
        }

        cout << ans << endl;
    }
}
