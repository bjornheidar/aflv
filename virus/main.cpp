#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string origin, infected;
    getline(cin, origin);
    getline(cin, infected);

    int minlen = min(origin.length(), infected.length());

    //special case
    if(infected.length() == 1){
        if(infected[0] == origin[0] || infected[0] == origin[origin.length()-1])
            cout << "0" << endl;
        else
            cout << "1" << endl;

        return 0;
    }
    if(origin.length() == 1){
        if(origin[0] == infected[0] || origin[0] == infected[infected.length()-1])
            cout << infected.length()-1 << endl;
        else
            cout << infected.length() << endl;

        return 0;
    }

    int startPos;
    for (startPos = 0; startPos < minlen; ++startPos) {
        if(origin[startPos] != infected[startPos])
            break;
    }

    int endpos1 = origin.length(), endpos2 = infected.length();
    for (int i = 0; i < minlen; ++i) {
        endpos1--;
        endpos2--;
        if(origin[endpos1] != infected[endpos2])
            break;
    }

    //cout << endpos2 << " " << endpos1 << endl;

    int ans = endpos2 - (startPos - 1);
    if(ans < 0) {
        if (origin.length() < infected.length())
            ans = infected.length() - origin.length();
        else
            ans = 0;
    }

    cout << ans << endl;

    return 0;
}