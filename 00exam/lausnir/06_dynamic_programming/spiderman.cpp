// Author: Björn Ingi Baldvinsson

#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <string>

using namespace std;

int INF = 501;
int m;
int d[40];
char path2[40];
int mem[40][1001];
string path;
string paths;

int mh = 501;

int opt(int i, int x) {
    if (x < 0 || x > mh) return INF;
    if (i == m){
        if(x == 0){ // finna hver maxhæðin er
            int tmp = 0;
            int mt = 0;
            for(int j = 0; j < m; j++){
                if(path2[j] == 'U'){
                    tmp += d[j];
                }
                else{
                    tmp -= d[j];
                }
                mt = max(mt, tmp);
            }
            mh = mt;
            path2[m] = '\0';
            paths = string(path2);
            return x;
        }
        else{
            return INF;
        }
    }

    if (mem[i][x] != 0){
        //cout << "i: " << i << " x: " << x << endl;
        return mem[i][x];

    }

    int res;


    path2[i] = 'D';
    int a = opt(i + 1, x - d[i]); // að fara niður


    path2[i] = 'U';
    int b = opt(i + 1, x + d[i]); // að fara upp



    res = min(a, b);

    mem[i][x] = res;
    return res;
}


int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        memset(mem, 0, sizeof(mem));

        paths = string();
        mh = INF;
        cin >> m;
        path = string(m, '?');
        for(int j = 0; j < m; j++){
            int dis;
            cin >> dis;
            d[j] = dis;
        }
        opt(0, 0);
        if(mh == INF){
            cout << "IMPOSSIBLE" << endl;
        }
        else{
            cout << paths << endl;
        }
    }


    return 0;
}
