#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> v1, vector<int> v2){
    for (int i = 0; i < v1.size(); ++i) {
        if(v1[i] == v2[i]){
            int v2pos = 0;
            for (int j = i; j != i; j = (j+1) % v1.size()) {
                if(v1[j] != v2[v2pos])
                    break;
                if(j == i-1)
                    return true;

                v2pos++;
            }
        }
    }

    return false;
}

int main() {
    int hands;
    cin >> hands;

    vector<int> c1(hands), c2(hands);
    for (int i = 0; i < hands; ++i) {
        cin >> c1[i];
    }
    for (int i = 0; i < hands; ++i) {
        cin >> c2[i];
    }

    sort(c1.begin(), c1.end(), greater<int>());
    sort(c2.begin(), c2.end(), greater<int>());

    vector<int> diff1(hands-1), diff2(hands-1);
    for (int i = 0; i < hands-1; ++i) {
        diff1[i] = c1[i] - c1[i+1];
        diff2[i] = c2[i] - c2[i+1];
    }
    //diff1[diff1.size()-1] = (360000 - c1[c1.size()-1]) + c1[0];
    //diff2[diff2.size()-1] = (360000 - c2[c2.size()-1]) + c2[0];

    for (int i = 0; i < diff1.size(); ++i) {
        cout << diff1[i] << " " << diff2[i] << endl;
    }

    if(check(diff1, diff2))
        cout << "possible";
    else
        cout << "impossible";
}