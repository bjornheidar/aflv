#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1000000;
vector<int> adj[1000];
vector<int> horror;
vector<int> HI(1000, INF);


int main(){
    int N, H, L;
    scanf("%d %d %d", &N, &H, &L);

    int h;
    for(int i = 0; i < H; i++){
        cin >> h;
        horror.push_back(h);
        HI[h] = 0;
    }

    int x, y;
    for(int i = 0; i < L; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int j = 0; j < horror.size(); j++){
        int start = horror[j];
        queue<int> Q;
        vector<bool> visited(1000, false);
        Q.push(start);
        visited[start] = true;
        int dist = 1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (!visited[v]) {
                    if(HI[v] > dist){
                        Q.push(v);
                    }
                    HI[v] = min(dist, HI[v]);
                    visited[v] = true;
                }
            }
            dist++;
        }
        visited.clear();
    }
    int highest = -1;
    int id = -1;
    for(int i = 0; i < N; i++){
        if(HI[i] > highest){
            highest = HI[i];
            id = i;
        }
    }

    cout << id;

    return 0;
}