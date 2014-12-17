// Author: Hafdís Erla Helgadóttir

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<vi> vvi;

short mem[9000000];

short play(int board) {
    if (!board) return 0;
	if (!(~board)) return 23;
	if (mem[board] != -1) return mem[board];
	short res = bitset<23>(board).count();
	for (int i = 0; i < 23; i++) {
		if ((board >> i) & 1) {
			int t;
			//right
			if (i < 21 && ((board >> (i + 1)) & 1) && !((board >> (i + 2)) & 1)) {
				t = board;
				t = t ^ (1 << i);
				t = t ^ (1 << (i+1));
				t = t | (1 << (i+2));
				res = min(res, play(t));
			}
			//left
			if (i > 1 && ((board >> (i - 1)) & 1) && !((board >> (i - 2)) & 1)) {
				t = board;
				t = t ^ (1 << i);
				t = t ^ (1 << (i - 1));
				t = t | (1 << (i - 2));
				res = min(res, play(t));
			}
		}	
	}
	mem[board] = res;
	return res;
}

int populate(string a) {
	int omg = 0;
	for (int i = 0; i < 23; i++) {
		if (a[i] == 'o') {
			omg = omg | (1 << i);
		}
	}
	return omg;
}

int main() {
	int tc;
	memset(mem, -1, sizeof(mem));
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		string s;
		cin >> s;
		int pop = populate(s);
		short res = play(pop);
		printf("%d\n", res);
	}
	return 0;
}
