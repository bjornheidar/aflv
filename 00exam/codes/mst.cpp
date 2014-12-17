bool edge_cmp(const edge &a, const edge &b) {
	return a.weight < b.weight;
}

vector<edge> mst(int n, vector<edge> edges) {
	union_find uf(n);
	sort(edges.begin(), edges.end(), edge_cmp);
	vector<edge> res;
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].u,
		v = edges[i].v;
		if (uf.find(u) != uf.find(v)) {
			uf.unite(u, v);
			res.push_back(edges[i]);
		}
	}
	return res;
}