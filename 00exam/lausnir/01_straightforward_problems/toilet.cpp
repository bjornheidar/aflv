// Author: Atli Sævar Guðmundsson

#include <iostream>
using namespace std;

int alwaysUp(string inp) {
	int cntAdj = 0;
	if (inp[0] == 'D') {
		cntAdj++;
	}
	for (int i = cntAdj + 1; i < inp.length(); i++) {
		if (inp[i] == 'D') {
			cntAdj += 2;
		}
	}
	return cntAdj;
}

int alwaysDown(string inp) {
	int cntAdj = 0;
	if (inp[0] == 'U') {
		cntAdj++;
	}
	for (int i = cntAdj + 1; i < inp.length(); i++) {
		if (inp[i] == 'U') {
			cntAdj += 2;
		}
	}
	return cntAdj;
}

int alwaysMyWay(string inp) {
	int cntAdj = 0;
	for (int i = 1; i < inp.length(); i++) {
		if (inp[i] != inp[i - 1]) {
			cntAdj++;
		}
	}
	return cntAdj;
}

int main () {
	string inp;
	cin >> inp;
	
	cout << alwaysUp(inp) << endl;
	cout << alwaysDown(inp) << endl;
	cout << alwaysMyWay(inp) << endl;

    return 0;
}
