/*
 * =======================================================================
 *      Filename: getShorty.cpp
 *   Description: Find the shortest path in the given graph.
 *       Version: 1.0
 *
 *       Created: 2014-12-11 18:16
 *        Author: Davíð Guðni Halldórssonm, davidgh13@ru.is
 * ========================================================================
 */

#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;

struct edge {
  int v;
  double weight;
  bool checked;
};

const int INF = 0;
vector<double> dist(10005);
vector<edge> adj[10005];

void dijkstra(int start) {
  dist[start] = 1;
  priority_queue<pair<double, int> > pq;
  pq.push(make_pair(dist[start], start));

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (int i = adj[u].size()-1; i >= 0; i--) {
      int v = adj[u][i].v;
      double w = adj[u][i].weight;
      adj[u].pop_back();

      if (w * dist[u] > dist[v]) {
        dist[v] = w * dist[u];
        pq.push(make_pair(dist[v], v));
      }
    }
  }
}


int main() {
  int n, m;
  while(cin >> n) {
    scanf("%d", &m);

    if(n == 0 || m == 0) continue;

    for(int i = 0; i < n; i++) {
      dist[i] = INF;
    }

    for(int i = 0; i < m; i++) {
      int v1, v2;
      double f;
      scanf("%d %d %lf", &v1, &v2, &f);

      edge e1, e2;
      e1.v = v1;
      e2.v = v2;
      e1.weight = f;
      e2.weight = f;
      e1.checked = false;
      e2.checked = false;

      adj[v1].push_back(e2);
      adj[v2].push_back(e1);
    }

    dijkstra(0);

    printf("%.4f\n", dist[n-1]);
  }
  return 0;
}
