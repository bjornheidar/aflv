// Author: Atli Sævar Guðmundsson

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main () {
	
	vector<int> que[48];
	priority_queue<int> Q;
	
	int N, T;
	cin >> N >> T;
	
	int c, t;
	for (int p = 0; p < N; p++) {
		
		cin >> c >> t;
		que[t].push_back(c);
	}
	
	int sum = 0;
	
	for (int i = T - 1; i >= 0; i--) {
		if (!que[i].empty()) {
			for (int j = 0; j < que[i].size(); j++) {
				Q.push(que[i][j]);
			}
			sum += Q.top();
			Q.pop();
		}
	}
	
	cout << sum << endl;
	
    return 0;
}
