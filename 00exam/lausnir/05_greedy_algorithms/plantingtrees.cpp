// Author: Björn Ingi Baldvinsson

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> vec;

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        vec.push_back(t);
    }

    sort(vec.begin(), vec.end(), greater<int>());

    int maxd = 1;
    for(int i = 0; i < n; i++){
        int today = i+1;
        if(today + vec[i] > maxd)
            maxd = today + vec[i];
    }

    cout << maxd + 1 << endl;
    return 0;
}
