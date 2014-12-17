// Author: Gunnar Páll Gunnarsson

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    char arr[1000][1000];
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    queue<pair<int, int> > qu;
    for (int i = 0; i < n; ++i) {
        qu.push(make_pair(i, 0));
        qu.push(make_pair(i, m-1));
    }
    for (int i = 0; i < m; ++i) {
        qu.push(make_pair(0, i));
        qu.push(make_pair(n-1, i));
    }

    int sum = 0;
    while (!qu.empty()) {
        pair<int, int> par = qu.front();
        qu.pop();
        if (par.first < 0 || par.second < 0 || par.first >= n || par.second >= m)
            continue;

        if (arr[par.first][par.second] == '1')
            ++sum;
        else if (arr[par.first][par.second] == '0') {
            arr[par.first][par.second] = '2';
            qu.push(make_pair(par.first, par.second+1));
            qu.push(make_pair(par.first, par.second-1));
            qu.push(make_pair(par.first+1, par.second));
            qu.push(make_pair(par.first-1, par.second));
        }
    }
    cout << sum << endl;
    return 0;
}
