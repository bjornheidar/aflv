#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool vowel(char c){
    return c == 'a' ||
        c == 'e' ||
        c == 'i' ||
        c == 'o' ||
        c == 'u';
}

int main() {
    vector<char> decoded;

    string coded;
    getline(cin, coded);

    decoded.push_back(coded[0]);
    for (int i = 1; i < coded.length(); ++i) {
        char c = coded[i];
        if(c != 'p' || i == coded.length()-1)
            decoded.push_back(coded[i]);
        else{
            if(vowel(coded[i-1]) && coded[i-1] == coded[i+1])
                i++;
            else
                decoded.push_back(c);
        }
    }

    for (int i = 0; i < decoded.size(); ++i) {
        cout << decoded[i];
    }

    return 0;
}