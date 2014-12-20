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
    //verk B
    /*string line;
    int lines = 0, max = 0;
    int length[100];
    while(!cin.eof()){
        getline(cin, line);
        length[lines] = line.length();
        if(line.length() > max)
            max = line.length();
        lines++;
    }

    int raggedness = 0;
    for (int i = 0; i < lines-1; ++i) {
        raggedness += pow(max - length[i], 2);
    }

    cout << raggedness;*/

    int scores [5] = {0,0,0,0,0};

    for (int i = 0; i < 5; ++i) {
        int s [4];
        cin >> s[0] >> s[1] >> s[2] >> s[3];
        int posIn = 0;
        for (int j = 0; j < 5; ++j) {
            if(j != i) {
                scores[i] += s[posIn];
                posIn++;
            }
        }
    }

    int c = 0, s = 0;
    for (int i = 0; i < 5; ++i) {
        if(scores[i] > s){
            c = i;
            s = scores[i];
        }
    }

    cout << c+1 << " " << s << endl;

    return 0;
}