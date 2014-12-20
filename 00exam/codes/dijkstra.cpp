struct edge {
	int u, v;
	int weight;
	edge(int _u, int _v, int _w) {
		u = _u;
		v = _v;
		weight = _w;
	}
};

vector<edge> adj[100];
vector<int> dist(100, INF);

void dijkstra(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>,
	vector<pair<int, int> >,
	greater<pair<int, int> > > pq;
	pq.push(make_pair(dist[start], start));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].v;
			int w = adj[u][i].weight;
			if (w + dist[u] < dist[v]) {
				dist[v] = w + dist[u];
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}