#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<int> adj[10000];
vector<int> component(10000, -1);

void find_component(int cur_comp, int u) {
    if (component[u] != -1) {
        return;
    }
    component[u] = cur_comp;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        find_component(cur_comp, v);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    int owed[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &owed[i]);
    }
    for (int i = 0; i < m; ++i) {
        int a,b;
        scanf("%d %d", &a, &b);

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int components = 0;
    for (int u = 0; u < n; u++) {
        if (component[u] == -1) {
            find_component(components, u);
            components++;
        }
    }

    vector<int> totals (components, 0);
    for (int i = 0; i < n; ++i) {
        totals[component[i]] += owed[i];
    }

    for (int i = 0; i < totals.size(); ++i) {
        if(totals[i] != 0){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << "POSSIBLE" << endl;

    return 0;
}