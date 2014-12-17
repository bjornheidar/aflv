// Author: Björn Ingi Baldvinsson

#include <iostream>
#include <string>


using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    string org, alt;
    cin >> org >> alt;

    int l = 0;
    int Or = org.length() - 1;
    int Ar = alt.length() - 1;

    while(org[l] == alt[l] && l <= Or && l <= Ar){
        l++;
    }
    l--;

    while(org[Or] == alt[Ar] && Ar > l && Or > l){
        Or--;
        Ar--;
    }
    Ar++;
    cout << Ar - l - 1 << endl;

    return 0;
}
