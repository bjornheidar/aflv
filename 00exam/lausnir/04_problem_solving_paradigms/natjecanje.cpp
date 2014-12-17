// Author: Ása Björk Valdimarsdóttir

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{

    int T = 0, D = 0, R = 0;

    scanf("%d", &T);
    scanf("%d", &D);
    scanf("%d", &R);

    vector<int> damaged;
    bool reserve[T+1];

    for(int t = 0; t < T+1; t++) reserve[t] = false;

    int dam = 0, rev = 0, counter = 0;

    for(int d = 0; d < D; d++){
        scanf("%d", &dam);
        damaged.push_back(dam);
    }

    for(int r = 0; r < R; r++){
        scanf("%d", &rev);
        reserve[rev] = true;
    }

    for(unsigned d = 0; d < damaged.size(); d++){
        dam = damaged[d];

        if(reserve[dam-1]){
            reserve[dam-1] = false;
        }
        else if(reserve[dam+1]){
            reserve[dam+1] = false;
        }
        else counter ++;

        }

    cout << counter;
    return 0;
}
