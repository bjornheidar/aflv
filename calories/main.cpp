#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int gtoC[5] = {9, 4, 4, 4, 7};

void handle_case(vector<string> v){
    stringstream ss;
    vector<pair<double, double> > fatsandtotals;
    for (int i = 0; i < v.size(); ++i) {
        pair<char, int> fat;
        ss.str(v[i]);
        int perc = 0;
        double total = 0;
        for (int j = 0; j < 5; ++j) {
            char t;
            int amount;
            ss >> amount >> t;
            if(j == 0){
                fat.first = t;
                fat.second = amount;
            }
            if(amount > 0) {
                switch (t) {
                    case '%':
                        perc += amount;
                        break;
                    case 'C':
                        total += amount;
                        break;
                    case 'g':
                        total += amount * gtoC[j];
                        break;
                }
            }
            //cout << j << ":  " << total << endl;
        }
        if(perc != 100)
            total = total / ((double)(100 - perc) / 100);

        //cout << "after perc: " << total << endl;

        double f = 0.0;
        if(fat.first == '%')
            f = total * ((double)fat.second / 100);
        else if(fat.first == 'g')
            f = fat.second*gtoC[0];
        else
            f = fat.second;

        fatsandtotals.push_back(make_pair(f, total));
    }

    double fats = 0, totals = 0;
    for (int i = 0; i < fatsandtotals.size(); ++i) {
        fats += fatsandtotals[i].first;
        totals += fatsandtotals[i].second;
    }

    //cout << fats << " " << totals << endl;

    int ans = (int)(round((fats / totals)*100));
    cout << ans << "%" << endl;
}

int main() {
    vector<vector<string> > cases;
    vector<string> thiscase;
    while(true){
        string s;
        getline(cin, s);
        if(s.length() != 1){
            thiscase.push_back(s);
        }
        else{
            if(thiscase.size() == 0)
                break;
            else{
                cases.push_back(vector<string>(thiscase.begin(), thiscase.end()));
                thiscase.clear();
            }
        }
    }

    for (int i = 0; i < cases.size(); ++i) {
        handle_case(cases[i]);
    }
}