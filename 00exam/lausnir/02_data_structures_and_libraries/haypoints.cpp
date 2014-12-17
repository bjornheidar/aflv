// Author: Björn Heiðar Rúnarsson

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int dict, desc;
    cin >> dict >> desc;
    map<string, int> salary;
    //populate dictionary
    for (int i = 0; i < dict; ++i) {
        pair<string, int> p;
        cin >> p.first >> p.second;
        salary.insert(p);
    }
    //calculate salaries
    int out[desc];
    for (int i = 0; i < desc; ++i) {
        int total = 0;
        while(true){
            string s;
            cin >> s;
            if(s == ".")
                break;

            map<string, int>::iterator it = salary.find(s);
            if(it != salary.end())
                total += it->second;
        }
        out[i] = total;
    }
    //output
    for (int i = 0; i < desc; ++i) {
        cout << out[i] << endl;
    }
}
