// Author: Andri Már Sigurðsson

#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
using namespace std;


struct union_find {
    int parent[10000];
    int sizes[10000];
    union_find(int n) {
        for (int i = 0; i < n * 2 && i < 10000; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }
    }
    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    int unite(int x, int y) {
        int tX = find(x), tY = find(y);
        if(tX != tY) sizes[tY] += sizes[tX];
        parent[tX] = tY;
        return sizes[tY];
    }

};

int main() {
    int n, k;
    pair<map<string,int>::iterator, bool>aIt, bIt;
    char aS[20], bS[20];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int counter = 0;
        map<string, int> friendStalker;
        scanf("%d", &k);
        union_find p = union_find(k);
        for (int j = 0; j < k; ++j) {
            scanf("%s %s", &aS, &bS);
            aIt = friendStalker.insert(pair<string, int>(aS,counter));
            if(aIt.second)counter++;
            bIt = friendStalker.insert(pair<string, int>(bS,counter));
            if(bIt.second)counter++;
            printf("%d\n",p.unite(aIt.first->second, bIt.first->second));
        }
    }
    return 0;
}
