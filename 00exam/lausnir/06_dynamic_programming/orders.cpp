// Author: Sævar Örn Kjartansson

#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int sols;
int d[100];
int memo[100][30001];
bool taken[100][30001];

int solution_cnt(int i, int p) {
    
    if (i == -1)
        return 0;
    if (p < 0)
        return 0;
    if (p == 0)
        return 1;

    if (memo[i][p] != -1)
        return memo[i][p];

    int a, b;

    a = solution_cnt(i, p-d[i]);

    if (a > 1)
        return a;

    b = solution_cnt(i-1, p);

    if (a)
        taken[i][p] = true;
    
    memo[i][p] = a+b;

    return a+b;
}

bool first;
void find_solution(int i, int p) {

    if (i == -1)
        return;
   
    if (taken[i][p]) {
        find_solution(i, p-d[i]);

        if (!first)
            printf(" ");
        first = false;

        printf("%d", i+1);
    }
    else
        find_solution(i-1, p);
}


int main() {
    
    int N, M;
    
    memset(taken, 0, sizeof(taken));
    memset(memo, -1, sizeof(memo));

    scanf("%d\n", &N);

    for (int t = 0; t < N; t++)
        scanf("%d", d + t);

    scanf("%d\n", &M);

    for (int t = 0; t < M; t++) {

        int p;
        scanf("%d", &p);

        int cnt = solution_cnt(N-1, p);
        if (cnt == 1) {
            first = true;
            find_solution(N-1, p);
            printf("\n");
        }
        else if (cnt == 0)
            printf("Impossible\n");
        else
            printf("Ambiguous\n");

    }
}
