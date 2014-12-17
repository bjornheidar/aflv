// Author: Björn Orri Sæmundsson

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int length = 1;
        int mod = 1 % n;
        while(mod != 0) {
            mod = (mod * 10 + 1) % n;
            length++;
        }
        printf("%d\n", length);
    }
    return 0;
}
