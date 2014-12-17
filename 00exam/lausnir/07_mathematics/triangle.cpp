// Author: Björn Orri Sæmundsson

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int n;
    int tcase = 1;
    const double log3 = log10(3);
    while(scanf("%d", &n) != EOF) {
        int length = ceil(n * log10(1.5) + log3);
        printf("Case %d: %d\n", tcase, length);
        tcase++;
    }
    return 0;
}
