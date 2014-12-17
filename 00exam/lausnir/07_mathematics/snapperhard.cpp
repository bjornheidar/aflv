// Author: Egill Sveinbjörnsson

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n, t, k;
    cin >> n;

    for (int j = 1; j <= n; ++j)  {
        cin >> t >> k;
        int bits = (1 << t) - 1;
        int ans = k & bits;

        if (ans == bits) {
            printf("Case #%d: ON\n", j);
        } else {
            printf("Case #%d: OFF\n", j);
        }
    }

    return 0;
}
