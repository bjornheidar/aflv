#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int test_cases;
    scanf("%d", &test_cases);
    for (int i = 1; i <= test_cases; ++i) {
        int N, K;
        scanf("%d %d", &N, &K);

        if((K+1) % (1<<N) == 0)
            printf("Case #%d: ON\n", i);
        else
            printf("Case #%d: OFF\n", i);
    }
}