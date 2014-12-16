#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int l, d, n;
    scanf("%d %d %d", &l, &d, &n);

    if(l < 12) {
        cout << 0;
        return 0;
    }

    vector<int> birds;
    birds.push_back(6);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        birds.push_back(x);
    }
    birds.push_back(l-4);

    sort(birds.begin(), birds.end());

    /*int start_pos = 6;
    int count = 0;
    for (int i = 0; i < birds.size(); ++i) {
        int high = birds[i];
        int x = (high - start_pos) / d;
        if(x > 0)
            count += x;
        start_pos = birds[i] + d;
    }*/

    int count = 0;
    for (int j = 0; j < birds.size()-1; ++j) {
        int start = 6;
        if(j != 0){
            start = birds[j] + d;
        }
        int end = birds[j+1] - d;

        cout << "start: " << start << " end: " << end << endl;

        if(end > l-6)
            break;

        int pos = start;
        while(true){
            count++;
            if(pos > end)
                break;
            pos += d;
        }
    }

    cout << count << endl;

    return 0;
}