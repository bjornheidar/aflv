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

int main()
{
    int T;
    cin >> T;
    while(T--){
        int startcol, startrow, destcol, destrow;
        char scol, dcol;
        cin >> scol >> startrow;
        startcol = scol - 'A';
        startrow--;
        cin >> dcol >> destrow;
        destcol = dcol - 'A';
        destrow--;

        if((startrow + startcol)%2 != (destrow + destcol)%2){
            cout << "Impossible" << endl;
        } else if(startrow == destrow && startcol == destcol){
            printf("0 %c %d\n", startcol + 'A', startrow+1);
        } else if( startrow-startcol == destrow-destcol
                || startrow+startcol == destrow+destcol){
            printf("1 %c %d %c %d\n", startcol + 'A', startrow+1, destcol+'A', destrow + 1);
        } else {
            int diffrow = destrow - startrow;
            int diffcol = destcol - startcol;

            int diff1 = (diffrow + diffcol)/2;
            int diff2 = (diffrow - diffcol)/2;

            if(startrow + diff2 < 8 && startrow + diff2 >= 0 && startcol - diff2 < 8 && startcol - diff2 >= 0){
                printf("2 %c %d %c %d %c %d\n", startcol + 'A', startrow+1, (startcol-diff2)+'A', startrow + diff2 + 1, destcol+'A', destrow + 1);
            }
            else if(startrow + diff1 < 8 && startrow + diff1 >= 0 && startcol + diff1 < 8 && startcol + diff1 >= 0){
                printf("2 %c %d %c %d %c %d\n", startcol + 'A', startrow+1, startcol+diff1+'A', startrow + diff1 + 1, destcol+'A', destrow + 1);
            }
        }
    }
}
