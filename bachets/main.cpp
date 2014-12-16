#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

vector<int> moves;
bool np[1000001];

void foo(int s){
    np[0] = true;
    for (int i = 1; i <= s; ++i) {
        for (int j = 0; j < moves.size(); ++j) {
            if(i >= moves[j]){
                if(np[i-moves[j]]) {
                    break;
                }
            }
            //We did not find a P position
            if(j == moves.size()-1) {
                np[i] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int stones, m;
    while(cin >> stones >> m){
        memset(np, false, sizeof(np));
        for (int i = 0; i < m; ++i) {
            int in;
            cin >> in;
            moves.push_back(in);
        }

        sort(moves.begin(), moves.end());

        foo(stones);

        if(np[stones])
            printf("Ollie wins\n");
        else
            printf("Stan wins\n");

        moves.clear();
    }

    return 0;
}