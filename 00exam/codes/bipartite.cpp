vector<int> adj[1000];
vector<int> side(1000, -1);
bool is_bipartite = true;
void check_bipartite(int u) {
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (side[v] == -1) {
			side[v] = 1 - side[u];
			check_bipartite(v);
		} else if (side[u] == side[v]) {
			is_bipartite = false;
		}
	}
}
for (int u = 0; u < n; u++) {
	if (side[u] == -1) {
		side[u] = 0;
		check_bipartite(u);
	}
}