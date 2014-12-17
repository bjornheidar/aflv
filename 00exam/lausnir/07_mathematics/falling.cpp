// Author: Ægir Már Jónsson

#include <stdio.h>
using namespace std;

int main() {
	int D;
	scanf("%d", &D);

	for(int x = 0; x <= D/2; x++) {
        for(int y = x; y * y - x * x <= D; y++) {
            //printf("Now at: %d(%d) - %d(%d) = %d\n", y * y, y, x * x, x, y * y - x * x);
            if(y * y - x * x == D) {
                printf("%d %d", x, y);
                return 0;
            }
        }
	}
	printf("impossible");

	return 0;
}
