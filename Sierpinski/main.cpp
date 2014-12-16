#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int n, c = 0;
    while(scanf("%d", &n) != EOF){
        c++;
        int ans = (int)floor(-n * log10(2) + (n+1) * log10(3)) +1;

        printf("Case %d: %d\n", c, ans);
    }
}