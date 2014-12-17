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

bool cmp(const ii &a, const ii &b) {
    if (a.second != b.second)
        return a.second < b.second;
    return a < b;
}

int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++) {
        int n, m;
        scanf("%d %d\n", &n, &m);
        m /= 2;

        vii events(n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d\n", &events[i].first, &events[i].second);
        }

        sort(events.begin(), events.end(), cmp);

        for (int iter = 0; iter < 3; iter++) {
            if (iter == 2) {
                printf("serious trouble\n");
                break;
            }

            vector<bool> finished(n, false);
            for (int i = 0; i < 100; i++) {
                if ((i % 7 == 5 || i % 7 == 6) && iter == 0)
                    continue;

                int left = m;
                for (int j = 0; j < n && left > 0; j++) {
                    if (finished[j]) continue;
                    if (!(events[j].first <= i && i <= events[j].second)) continue;
                    finished[j] = true;
                    left--;
                }
            }

            bool done = true;
            for (int i = 0; i < n; i++) {
                if (!finished[i]) {
                    done = false;
                    break;
                }
            }

            if (done) {
                if (iter == 0) {
                    printf("fine\n");
                    break;
                } else if  (iter == 1) {
                    printf("weekend work\n");
                    break;
                }
            }
        }
    }

    return 0;
}

