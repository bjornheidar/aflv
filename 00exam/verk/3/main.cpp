#include <cstdio>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(){
    int max_diff;
    scanf("%d\n", &max_diff);

    list<int> q;

    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); ++i) {
        if(str[i] == 'M')
            q.push_back(1);
        else
            q.push_back(-1);
    }

    //men are +1, women -1
    int diff = 0, count = 0;
    while(q.size() > 1){
        list<int>::iterator second = q.begin();
        second++;

        if(abs(diff + q.front()) <= abs(diff + *second)) {
            diff += q.front();
            q.pop_front();
        }
        else{
            diff += *second;
            q.erase(second);
        }

        if(max_diff < abs(diff))
            break;

        count++;
    }

    if(q.size() == 1){
        if(abs(diff + q.front()) <= max_diff)
            count++;
    }

    cout << count << endl;

    return 0;
}