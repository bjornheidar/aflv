// Author: Davíð Guðni Halldórsson

#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

const string welcome = "welcome to code jam";

void backTrack(string s, int scounter, int wcounter, int &value) {
    if(((int(welcome.length())-wcounter)-(int(s.length())-scounter)) > 0) {
        return;
    }

    if(wcounter >= 19) {
        value++;
        return;
    }

    if(s[scounter] != welcome[wcounter]) {
        backTrack(s, scounter+1, wcounter, value);
    }
    else {
        backTrack(s, scounter+1, wcounter+1, value);
        backTrack(s, scounter+1, wcounter, value);
    }
}

void output(int cas, int val) {
    cout << "Case #" << cas << ": ";
    //cout << endl << val << endl;
    val = val % 10000;
    if(val < 10) {
        cout << "000";
    }
    else if(val < 100) {
        cout << "00";
    }
    else if(val < 1000) {
        cout << "0";
    }
    cout << val << endl;
}


int main() {
    int n;
    scanf("%d", &n);

    //temp is just used to grab an empty line.
    string temp;
    getline(cin, temp);

    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);

        int val = 0;
        backTrack(s, 0, 0, val);
        output(i+1, val);
    }
    return 0;
}
