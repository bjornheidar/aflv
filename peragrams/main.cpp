#include <iostream>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    int freq[26];
    for(int i = 0; i < 26; ++i)
        freq[i] = 0;

    for (int i = 0; i < str.length(); ++i) {
        freq[str[i]-97] ++;
    }

    bool odd = false;
    int toChange = 0;
    for (int i = 0; i < 26; ++i) {
        int f = freq[i];
        if(f % 2 != 0){
            if(odd)
                toChange++;
            else
                odd = true;
        }
    }

    cout << toChange << endl;
}