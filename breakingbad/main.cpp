#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> adj[100000];
vector<int> side(100000, -1);
bool is_bipartite = true;

void check_bipartite(int u) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (side[v] == -1) {
            side[v] = 1 - side[u];
            check_bipartite(v);
        } else if (side[u] == side[v]) {
            is_bipartite = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int items;
    cin >> items;

    map<string, int> itemToNum;
    map<int, string> numToItem;

    for (int i = 0; i < items; ++i) {
        string item;
        cin >> item;
        itemToNum.insert(make_pair(item, i));
        numToItem.insert(make_pair(i, item));
    }

    int suspicious;
    cin >> suspicious;

    //construct adj list
    for (int i = 0; i < suspicious; ++i) {
        string item1, item2;
        cin >> item1 >> item2;

        adj[itemToNum[item1]].push_back(itemToNum[item2]);
        adj[itemToNum[item2]].push_back(itemToNum[item1]);
    }

    for (int i = 0; i < items; i++) {
        if (side[i] == -1) {
            side[i] = 0;
            check_bipartite(i);
        }
    }

    vector<string> walter, jesse;

    if(is_bipartite) {
        for (int i = 0; i < items; ++i) {
            if(side[i] == 0)
                walter.push_back(numToItem[i]);
            else
                jesse.push_back(numToItem[i]);
        }
        for (int i = 0; i < walter.size(); ++i) {
            cout << walter[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < jesse.size(); ++i) {
            cout << jesse[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "impossible" << endl;
}