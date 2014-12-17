#include <string>
#include <map>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

struct mycomp{
    bool operator()(const std::pair<string, int> &left, const std::pair<string,int> &right) {
        return left.second > right.second;
    }
};

deque<vector<string> > last7;

void display(int n){
    //count
    map<string, int> count;
    for(deque<vector<string> >::iterator it = last7.begin(); it != last7.end(); it++){
        for (int i = 0; i < it->size(); ++i) {
            if(!count.insert(pair<string, int>(it->at(i), 1)).second)
                count[it->at(i)]++;
        }
    }

    //prep for print
    vector<pair<string, int> > out(count.begin(), count.end());
    sort(out.begin(), out.end(), mycomp());
    int top = n, currentCount = out[0].second, prevpos = 0, endpos = out.size();

    for (int i = 0; i < out.size(); ++i) {
        if(out[i].second != currentCount){
            sort(out.begin()+prevpos, out.begin()+i);
            prevpos = i;
            currentCount = out[i].second;
            top--;
            if(top == 0){
                endpos = i;
                break;
            }
        }
    }
    //special case, all diffrent words only appear once
    if(currentCount == out[0].second)
        sort(out.begin(), out.end());

    //print
    cout << "<top " << n << ">" << endl;
    for (int j = 0; j < endpos; ++j) {
        cout << out[j].first << " " << out[j].second << endl;
    }
    cout << "</top>" << endl;
};

int main() {
    ios_base::sync_with_stdio(false);

    while(!cin.eof()){
        string word;
        cin >> word;
        if(word == "<text>"){
            if(last7.size() == 7)
                last7.pop_back();
            last7.push_front(vector<string>());
        }
        else if(word == "</text>"){
            continue;
        }
        else if(word == "<top"){
            int n;
            cin >> n >> word;
            display(n);
        }
        else{
            if(4 <= word.length())
                last7.front().push_back(word);
        }
    }
}