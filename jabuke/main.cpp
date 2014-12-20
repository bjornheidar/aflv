#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int,int> point;
point triangle [3];
/*double*/ int triangleArea;

//const double EPS = 1e-9;

double triangle_area(point p1, point p2, point p3){
    return abs(p1.first*(p2.second - p3.second) + p2.first*(p3.second - p1.second) + p3.first*(p1.second - p2.second));
}

bool point_in_triangle(point p){
    int a = triangle_area(p, triangle[0], triangle[1])
                + triangle_area(p, triangle[0], triangle[2])
                + triangle_area(p, triangle[1], triangle[2]);

    /*return abs(a - triangleArea) <= EPS;*/
    return a == triangleArea;
}

int main() {
    for (int i = 0; i < 3; ++i) {
        cin >> triangle[i].first >> triangle[i].second;
    }
    triangleArea = triangle_area(triangle[0], triangle[1], triangle[2]);

    int ntrees;
    cin >> ntrees;
    vector<point> trees(ntrees);
    for (int i = 0; i < ntrees; ++i) {
        cin >> trees[i].first >> trees[i].second;
    }

    int owned = 0;
    for (int i = 0; i < trees.size(); ++i) {
        if(point_in_triangle(trees[i]))
            owned++;
    }

    double dasArea = (double)triangleArea/2.0;
    cout.precision(1);
    cout << fixed << dasArea << endl;
    cout << owned;
}