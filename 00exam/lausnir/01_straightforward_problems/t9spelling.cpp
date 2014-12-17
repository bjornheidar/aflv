// Author: Tómas Magnússon

#include "stdio.h"

int map1[26] = { 2, 22, 222, 3, 33, 333, 4, 44, 444, 5, 55, 555, 6,
    66, 666, 7, 77, 777, 7777, 8, 88, 888, 9, 99, 999, 9999 };
int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    for(int t = 0; t < T; ++t){
        printf("Case #%d: ", t+1);
        int last = -1;
        int c;
        while((c = getchar()) != '\n'){
            //putchar(c);
            if(c == ' '){
                if(last == 0) putchar(' ');
                last = 0;
                putchar('0');
            } else {
                int num = map1[c-'a'];
                if ((num%10) == last) putchar(' ');
                last = num % 10;
                printf("%d", num);
            }
        }
        putchar('\n');
    }
}
