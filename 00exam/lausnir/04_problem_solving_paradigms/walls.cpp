// Author: Sævar Örn Kjartansson

#include <stdio.h>
#include <string.h>

using namespace std;

int walls_reached(int l, int w, int x, int y, int r) {
    
    int reached = 0;

    if ((x+l/2.0)*(x+l/2.0) + y*y <= r*r)
        reached |= 1;
    if ((x-l/2.0)*(x-l/2.0) + y*y <= r*r)
        reached |= 2;
    if (x*x + (y+w/2.0)*(y+w/2.0) <= r*r)
        reached |= 4;
    if (x*x + (y-w/2.0)*(y-w/2.0) <= r*r)
        reached |= 8;

    return reached;
}

bool covers_all(bool *cranes, int reached, int n, int cnt) {
    
    if (reached == (1 << 4)-1)
        return true;

    if (cnt == 0 || n == (1<<4))
        return false;

    if (cranes[n] && covers_all(cranes, reached | n, n+1, cnt-1))
        return true;

    return covers_all(cranes, reached, n+1, cnt);
}


int main() {
    
    int l, w, n, r;

    scanf("%d %d %d %d\n", &l, &w, &n, &r);
    
    bool wall_subsets[1<<4];
    memset(wall_subsets, 0, sizeof(wall_subsets));

    for (int i = 0; i < n; i++) {
        
        int x, y;
        scanf("%d %d\n", &x, &y);

        int reached = walls_reached(l, w, x, y, r);
        if (!wall_subsets[reached])
            wall_subsets[reached] = true;
    }

    int i;
    for (i = 1; i <= 4; i++) {
        if (covers_all(wall_subsets, 0, 0, i)) {
            printf("%d\n", i);
            break;
        }
    }
    if (i == 5)
        printf("Impossible\n");

    return 0;
}


