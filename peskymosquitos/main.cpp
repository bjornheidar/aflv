#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<double, double> coord;
const double EPS = 1e-8;

inline double distSq(coord c1, coord c2){
    double diff1 = /*(c2.first-c1.first) < EPS ? 0.0 :*/ c2.first - c1.first;
    double diff2 = /*(c2.second-c1.second) < EPS ? 0.0 :*/ c2.second - c1.second;
    return diff1*diff1 + diff2*diff2;
    //return sqrt(pow(c2.first-c1.first, 2) + pow(c2.second-c1.second, 2)) - EPS;
}

int main() {
    ios_base::sync_with_stdio(false);

    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; ++i) {
        int mos;
        double bowl;
        cin >> mos >> bowl;

        vector<coord> mosquitos;
        for (int j = 0; j < mos; ++j) {
            double x, y;
            cin >> x >> y;
            mosquitos.push_back(coord(x, y));
        }

        if(bowl == 0.0){
            sort(mosquitos.begin(), mosquitos.end());
            int ans = 1;
            int count = 1;
            for (int j = 0; j < mosquitos.size()-1; ++j) {
                if(mosquitos[j] == mosquitos[j+1])
                    count++;
                else
                    count = 1;

                ans = max(ans, count);
            }

            cout << ans << endl;
        }
        else {
            bowl *= bowl;

            double distances[mos][mos];
            for (int j = 0; j < mos; ++j) {
                for (int k = 0; k < mos; ++k) {
                    distances[j][k] = -1;
                }
            }
            for (int j = 0; j < mosquitos.size(); ++j) {
                for (int k = j; k < mosquitos.size(); ++k) {
                    distances[j][k] = distances[k][j] = distSq(mosquitos[j], mosquitos[k]) - EPS;
                }
            }

            int ans = 1;
            for (int j = 0; j < mos; ++j) {
                vector<int> p;
                for (int k = 0; k < mos; ++k) {
                    if (distances[j][k] <= bowl + EPS) {
                        bool yes = true;
                        for (int l = 0; l < p.size(); ++l) {
                            if (distances[k][p[l]] >= bowl + EPS) {
                                yes = false;
                                break;
                            }
                        }
                        if (yes)
                            p.push_back(k);
                    }
                }
                /*cout << "p: ";
                for (int m = 0; m < p.size(); ++m) {
                    cout << p[m] << " ";
                }
                cout << endl;*/
                ans = max(ans, (int) p.size());
            }

            /*cout << mos << " " << bowl << endl;
            for (int m = 0; m < mos; ++m) {
                for (int j = 0; j < mos; ++j) {
                    cout << distances[m][j] << " ";
                }
                cout << endl;
            }*/

            cout << ans << endl;
        }
    }
}