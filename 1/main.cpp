#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(){
    int n,p, q;
    cin >> n;
    cin >> p;
    cin >> q;
    if(((p+q)/n % 2) == 0)
        cout << "paul" << endl;
    else
        cout << "opponent" << endl;

    return 0;
}