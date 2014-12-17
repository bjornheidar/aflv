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

int win[200];
int los[200];

int main()
{
    int N, K;
    cin >> N;
    while(N != 0){
        cin >> K;
        memset(win, 0, N*sizeof(int));
        memset(los, 0, N*sizeof(int));
        for(int i = 0; i < K*N*(N-1)/2; ++i){
            int p1, p2;
            string m1, m2;
            cin >> p1 >> m1 >> p2 >> m2;
            p1--; p2--;
            if( (m1[0] == 'r' && m2[0] == 's') ||
                (m1[0] == 'p' && m2[0] == 'r') ||
                (m1[0] == 's' && m2[0] == 'p')){
                win[p1]++; los[p2]++;
            } else if( (m2[0] == 'r' && m1[0] == 's') ||
                (m2[0] == 'p' && m1[0] == 'r') ||
                (m2[0] == 's' && m1[0] == 'p')){
                win[p2]++; los[p1]++;
            }
        }
        for(int i = 0; i < N; ++i){
            if(win[i] + los[i] > 0){
                printf("%.3f\n", round(1000.0*static_cast<double>(win[i])/(win[i]+los[i]))/1000.0);
            } else {
                printf("-\n");
            }
        }
        cout << endl;
        cin >> N;
    }
}
