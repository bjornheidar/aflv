#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef pair<int,int> coord;

struct union_find {
    vector<int> parent;
    union_find(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    // find and union
    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        int n;
        cin >> n;

        int length = (n+2)*2;

        int locations [length];

        for (int j = 0; j < length; j+=2) {
            cin >> locations[j] >> locations[j+1];
        }

        union_find uf(102);
        for (int j = 0; j < length; j+=2) {
            for (int k = j+2; k < length; k+=2) {
                if((locations[k]-locations[j])+(locations[k+1] - locations[j+1]) <= 1000)
                    uf.unite(j/2, k/2);
           }
        }

        if(uf.find(0) == uf.find(n+1))
            cout << "happy" << endl;
        else
            cout << "sad" << endl;
    }
}