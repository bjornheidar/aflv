#include <iostream>
#include <vector>

using namespace std;

bool vowel(char c){
    return c == 'a' ||
            c == 'e' ||
            c == 'i' ||
            c == 'o' ||
            c == 'u';
}

int main() {
    string coded;
    getline(cin, coded);

    vector<bool> marked(coded.length(), false);

    for (int i = 1; i < coded.length()-1; ++i) {
        if(coded[i] == 'p' && !marked[i-1]){
            if(vowel(coded[i-1]) && coded[i-1] == coded[i+1]){
                marked[i] = marked[i+1] = true;
            }
        }
    }

    for (int j = 0; j < coded.length(); ++j) {
        if(!marked[j])
            cout << coded[j];
    }
}