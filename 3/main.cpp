#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void func(int c){
    int n;
    cin >> n;
    vector<int> blues, reds;
    for (int i = 0; i < n; ++i) {
        int x;
        char s;
        scanf("%d%c", &x, &s);

        if (s == 'R')
            reds.push_back(x);
        else
            blues.push_back(x);
    }

    if(reds.empty() || blues.empty()){
        cout << "Case #" << c << ": 0" << endl;
        return;
    }

    sort(reds.rbegin(), reds.rend());
    sort(blues.rbegin(), blues.rend());


    int length = 0;
    for (int j = 0; j < min(blues.size(), reds.size()); ++j) {
        length += blues[j] + reds[j];
    }
    length -= min(blues.size(), reds.size())*2;
    cout << "Case #" << c << ": " << length << endl;
}

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        func(i+1);
    }
}