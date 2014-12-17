// Author: Jörundur Jörundsson

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

struct Point{
	int x;
	int y;
};

struct Edge{
	int from;
	int to;
	double dist;
};

double distance(Point a, Point b){
	double tmp1 = static_cast<double>(a.x)-b.x;
	double tmp2 = static_cast<double>(a.y)-b.y;
	double deltaX = tmp1*tmp1;
	double deltaY = tmp2*tmp2;
	return sqrt(deltaX+deltaY);
}

//altered code for union_find by Bjarki Ágúst Guðmundsson
struct union_find {
	vector<int> parent;
	vector<int> size;
	int count;
    union_find(int n) {
		count = n;
		size = vector<int>(n,1);
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
		if(!connected(x, y)){
			size[find(y)] += size[find(x)];
			count--;
		}
        parent[find(x)] = find(y);
    }
	bool connected(int x, int y){
		return find(x) == find(y);
	}

};


int main(int argc, char *argv[]) {
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	
	int tests;
	cin >> tests;
	
	//for each test case
	for (int t = 0; t < tests; t++) {
		int S, P;
		cin >> S >> P;
		
		Point *point = new Point[P];
		Edge *edge = new Edge[P*P];
		
		for (int i = 0; i < P; i++) {
			cin >> point[i].x  >> point[i].y;
		}
		
		int counter = 0; //for number of edges
		
		for (int i = 0; i < P; i++) {
			for (int j = i+1; j < P; j++) {
				edge[counter].from = i;
				edge[counter].to = j;
				edge[counter].dist = distance(point[i], point[j]);
				counter++;
			}
		}

		double EPS = 1e-9, lo = 0, hi = 15000, mid;
		
		while (hi-lo > EPS) {
			union_find uf(P);
			mid = (lo+hi) / 2;
			for (int i = 0; i < counter; i++) {
				if (edge[i].dist <= mid){
					uf.unite(edge[i].from, edge[i].to);
				}
			}
			if (uf.count > S){
				lo = mid;
			} else {
				hi = mid;
			} 
		}
		cout << setprecision(2) << fixed << showpoint << lo << endl;
	}
	return 0;
}




