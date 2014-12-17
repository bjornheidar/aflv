// Author: Davíð Guðni Halldórsson

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

const int INF = 10000;
int bills[100];
int mem[100][10000];

int find(int i, int x) {
    if (x < 0) return INF;
    if (x == 0) return 0;
    if (i == -1) return INF;

    if (mem[i][x] != -1) return mem[i][x];

    int res = INF;
    int a = 1 + find(i - 1, x - bills[i]);
    int b = find(i - 1, x);

    res = min(a, b);
    mem[i][x] = res;
    return res;
}


int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int cents, n;
        scanf("%d", &cents);
        scanf("%d", &n);

        for(int j = 0; j < n; j++) {
            int bill;
            scanf("%d", &bill);

            bills[j] = bill;
        }

        memset(mem, -1, sizeof(mem));

        for(int j = cents; j < INF; j++) {
          if(find(n-1, j) != INF) {
            printf("%d %d\n", j, find(n-1, j));
            break;
          }
        }
    }

    return 0;
}
