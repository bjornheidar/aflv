#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <cmath>

using namespace std;

typedef complex<double> coord;

const double EPS = 1e-9;

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(2);

    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; ++i) {
        double bowl;
        int nmos;
        cin >> nmos >> bowl;
        
        vector<coord> mosquitoes(nmos);
        for (int j = 0; j < nmos; ++j) {
            double x, y;
            cin >> x >> y;
            mosquitoes[j] = coord(x,y);
        }

        if(bowl == 0.0){
            int ans = 1;
            int count = 1;
            for (int j = 0; j < mosquitoes.size()-1; ++j) {
                for (int k = j+1; k < mosquitoes.size(); ++k) {
                    if(mosquitoes[j] == mosquitoes[j+1])
                        count++;
                    else
                        count = 1;
                }
                ans = max(ans, count);
            }

            cout << ans << endl;
        }
        else{
            double dist [nmos][nmos];
            for (int j = 0; j < nmos; ++j) {
                for (int k = j; k < nmos; ++k) {
                    double d = abs(mosquitoes[j] - mosquitoes[k]);
                    dist[j][k] = dist[k][j] =  d > EPS ? d : 0.0;
                }
            }

            for (int j = 0; j < nmos; ++j) {
                for (int k = 0; k < nmos; ++k) {
                    cout << fixed << dist[j][k] << " ";
                }
                cout << endl;
            }

            int ans = 1;
            for (int j = 0; j < nmos; ++j) {
                vector<int> idx;
                for (int k = 0; k < nmos; ++k) {
                    if(dist[j][k] <= bowl){
                        bool oui = true;
                        for (int l = 0; l < idx.size(); ++l) {
                            if(dist[j][idx[l]] >= bowl){
                                oui = false;
                                break;
                            }
                        }
                        if(oui)
                            idx.push_back(k);
                    }
                }
                if(idx.size() > ans)
                    ans = idx.size();
            }
            cout << ans << endl;
        }
    }

    return 0;
}