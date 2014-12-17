// Author: Tómas Magnússon

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define foreach(u, o) \
    for (typeof((o).begin()) u = (o).begin(); u != (o).end(); ++u)
const int INF = 2147483647;
const double EPS = 1e-9;
const double pi = acos(-1);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T mod(T a, T b) { return (a % b + b) % b; }
template <class T> int size(const T &x) { return x.size(); }

int dist[600];
bool visited[600];

int move(int game, int mv){
    int x = mv % 3, y = mv / 3;
    game ^= (1 << mv);
    if(x > 0){
        game ^= (1 << (y*3 + (x-1)));
    }
    if(x < 2){
        game ^= (1 << (y*3 + (x+1)));
    }
    if(y > 0){
        game ^= (1 << ((y-1)*3 + x));
    }
    if(y < 2){
        game ^= (1 << ((y+1)*3 + x));
    }
    return game;
}

int main(){
    int T;
    //cin >> T;
    scanf("%d", &T);
    getchar();
    for(int t = 0; t < T; ++t){
        memset(visited, 0, sizeof visited);
        memset(dist, -1, sizeof dist);
        char c;
        int game = 0;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                c = getchar();
                if(c == '*'){
                    game |= (1 << (3*i + j));
                }
            }
            getchar();
        }
        //cout << game << endl;
        //for(int i = 0; i < 3; ++i){
            //for(int j = 0; j < 3; ++j){
                //printf("%d", (game & (1 << (3*i + j))) > 0);
            //}
            //printf("\n");
        //}
        queue<int> Q;
        Q.push(0);
        dist[0] = 0;
        visited[0] = true;
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            //cout << cur << endl;
            for(int i = 0; i < 9; ++i){
                int nxt = move(cur, i);
                assert( cur != nxt );
                if(!visited[nxt]){
                    dist[nxt] = dist[cur] + 1;
                    visited[nxt] = true;
                    Q.push(nxt);
                }
            }
        }
        cout << dist[game] << endl;
    }
}

