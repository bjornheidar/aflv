// Author: Daníel Benediktsson

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
#include <array>

using namespace std;

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        
        bool win[n + 1];
        memset(win, 0, sizeof win);

        int legalMoves[m];

        for(int i = 0; i < m; i++) {
            cin >> legalMoves[i];
        }

        for(int i = 0; i < (n + 1); i++) {
            if(!win[i]) {
                for(int j = 0; j < m; j++) {
                    if(i + legalMoves[j] < (n + 1)) {
                        win[i + legalMoves[j]] = true;
                    }
                }
            }
        }

        if(win[n]) {
            cout << "Stan wins" << endl;
        } else {
            cout << "Ollie wins" << endl;
        }

    }

    return 0;
}
