#include <iostream>
#include <list>
#include <string>
#include <stdlib.h>

using namespace std;

list<int> cookies;

inline void median(){
    cout << "median start" << endl;
    cout << cookies.size() << endl;

    cout << "sorting" << endl;
    cookies.sort();

    cout << "before c" << endl;
    int c;
    if(cookies.size() % 2 == 0)
        c = (cookies.size()/2) +1;
    else
        c = (cookies.size() +1) / 2;

    cout << "for" << endl;
    list<int>::iterator it = cookies.begin();
    for (int i = 0; i < c; ++i) {

        it++;
    }

    cout << "ans: " << *it << endl;

    cout << "erasing" << endl;
    cookies.erase(it);

    cout << cookies.size() << endl;

    cout << "median end" << endl;
}

inline void add_cookie(){
    return;
}

int main() {
    ios_base::sync_with_stdio(false);

    string d;

    cookies.sort();
    //cookies.push_back(1);


    while(!cin.eof()){
        cout << "running" << endl;
        getline(cin, d);

        if(d == "#"){
            cout << "To packaging" << endl;
            median();
        }
        else{
            cout << "adding cookie" << endl;
            cookies.push_back(atoi(d.c_str()));
        }

        cout << "end running" << endl;
    }

    return 0;
}