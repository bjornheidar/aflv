void bellman_ford(int n, int start) {
	dist[start] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			for (int j = 0; j < adj[u].size(); j++) {
				int v = adj[u][j].v;
				int w = adj[u][j].weight;
				dist[v] = min(dist[v], w + dist[u]);
			}
		}
	}
}