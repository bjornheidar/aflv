// Author: Bjarki Ágúst Guðmundsson

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo

bool pos(ll n, ll x, ll y) {
    if (n == 1) {
        return true;
    } else if (n == 2) {
        if (x == 1 && y == 1) return false;
        return true;
    } else {

        ll nx = x < n / 2 ? x : x - n / 2,
           ny = y < n / 2 ? y : y - n / 2;

        bool res = pos(n / 2, nx, ny);
        if (x >= n / 2 && y >= n / 2) {
            res = !res;
        }

        return res;
    }
}

int main() {

    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++) {
        ll n, x, y, w, h;
        cin >> n >> x >> y >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (j != 0) printf(" ");
                printf("%d", pos(n, y + i, x + j) ? 1 : -1);
            }

            printf("\n");
        }

        printf("\n");
    }

    return 0;
}

