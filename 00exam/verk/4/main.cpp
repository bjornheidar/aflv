#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const double EPS = 1e-09;

//Paradox with averages
int main() {
    ios_base::sync_with_stdio(false);

    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; ++i) {
        int cs, eco;
        cin >> cs >> eco;

        if(eco == 0){
            cout << cs << endl;
            break;
        }

        vector<int> csstuds(cs);

        int cstotaliq = 0, ecototaliq = 0;
        for (int j = 0; j < cs; ++j) {
            int iq;
            cin >> iq;
            csstuds[j] = iq;

            cstotaliq += iq;
        }
        for (int j = 0; j < eco; ++j) {
            int iq;
            cin >> iq;
            ecototaliq += iq;
        }

        int studs = 0;
        for (int k = 0; k < csstuds.size(); ++k){
            double csavg = (double)(cstotaliq - csstuds[k]) / (cs-1);
            double ecoavg = (double)(ecototaliq + csstuds[k]) / (eco+1);
            if(ecoavg < csstuds[k] && csstuds[k] < csavg)
                studs++;
        }

        cout << studs << endl;
    }


    //candy division
    /*long long num;
    cin >> num;

    vector<long long> numbers;
    numbers.push_back(0);
    numbers.push_back(num-1);

    /*if(num % 2 == 0){
        for (long long i = 2; i <= num/2; i += 2) {
            numbers.push_back(i-1);
        }
    }

    for (long long i = 2; i < (num/2)+1; ++i) {
        if(num % i == 0)
            numbers.push_back(i-1);
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }*/

    return 0;
}