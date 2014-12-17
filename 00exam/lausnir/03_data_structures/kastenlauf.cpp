// Author: Daníel Benediktsson4

#include <iostream>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

/* Union-find code taken from lecture
 * Author: Bjarki Ágúst Guðmundsson
*/
struct union_find {
    vector<int> parent;
    union_find(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
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
	int tc;
	cin >> tc;
	for(int i = 0; i < tc; i++) {
		int nstores;
		cin >> nstores;
		int xArr[nstores + 2], yArr[nstores + 2];
		union_find uf(nstores + 2);
		
		for(int j = 0; j < nstores + 2; j++) {
			cin >> xArr[j] >> yArr[j];
		}

		for(int j = 0; j < nstores + 2; j++) {
			for(int k = j + 1; k < nstores + 2; k++) {
				int dist = 0;
				// calculating the distance
				dist = (abs(xArr[j] - xArr[k])) + abs((yArr[j] - yArr[k]));
				// Jo and his friends can go 1000 meters with 20 beers
				if(dist <= 1000) {
					uf.unite(j, k);
				}
			}
		}

		// check if Jo's home is connected to Bergkirchweih
		if(uf.find(0) == uf.find(nstores + 1)) {
			cout << "happy" << endl;
		} else {
			cout << "sad" << endl;
		}
	}
	return 0;
}
