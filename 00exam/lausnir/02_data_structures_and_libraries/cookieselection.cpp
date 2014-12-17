// Author: Bertel Benóný Bertelsson

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

char d[10];

int main()
{
    multiset<unsigned int> v;
    multiset<unsigned int>::iterator it;
    multiset<unsigned int>::iterator tmp;
    while (scanf("%s\n", d) != EOF) {
        if (string(d) != "#") {
            unsigned int val = atoi(d);
            v.insert(val);
            if (v.size() == 1) it = v.begin();
            else if (val < *it  && (v.size() % 2 != 0)) --it;
            else if (val > *it  && (v.size() % 2 == 0)) ++it;
            else if (val == *it && (v.size() % 2 == 0)) ++it;
        }
        else if (string(d) == "#") {
            tmp = it;
            printf("%u\n", *it);
            if (v.size() % 2 == 0) {
                if (v.size() > 1) --it;
                v.erase(tmp);
            } else {
                if (v.size() != 1) ++it;
                v.erase(tmp);
            }
        }
    }
    return 0;
}
