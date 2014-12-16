#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);

    int N, T;
    cin >> N >> T;

    vector<pair<int, int> > customers;

    for (int i = 0; i < N; ++i) {
        int m, t;
        cin >> m >> t;

        customers.push_back(pair<int, int>(t, m));
    }

    sort(customers.begin(), customers.end());
    /*vector<bool> served(N, false);

    int ans = 0;
    for(int i = 0; i < T; i++){
        int best = 0, c, derp = 100;
        for (int j = 0; j < customers.size(); ++j) {
            if(i <= customers[j].first && customers[j].first <= derp){
                if(!served[j] && customers[j].first < derp){
                    derp = customers[j].first;
                }
                if(best < customers[j].second){
                    best = customers[j].second;
                    c = j;
                }
            }
        }

        served[c] = true;
        ans += best;
    }*/

    cout << ans << endl;
}