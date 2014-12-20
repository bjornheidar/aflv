#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

vector<bool> visited [100];
vector<bool> stars [100];
int xsize, ysize;

void search_from(int x, int y){
    if(x < 0 || xsize <= x
            || y < 0 || ysize <= y
                || !stars[x][y] || visited[x][y]) {
        return;
    }

    visited[x][y] = true;

    search_from(x-1, y);
    search_from(x+1, y);
    search_from(x, y-1);
    search_from(x, y+1);
}

int main() {
    int casenr = 1;
    while(scanf("%d %d", &xsize, &ysize) != EOF){
        string temp;
        getline(cin, temp);
        for (int i = 0; i < xsize; ++i) {
            //init vectors
            stars[i].assign(ysize, false);
            visited[i].assign(ysize, false);
            //read in
            string line;
            getline(cin, line);
            for (int j = 0; j < ysize; ++j) {
                stars[i][j] = (line[j] == '-');
            }
        }

        int count = 0;
        for (int i = 0; i < xsize; ++i) {
            for (int j = 0; j < ysize; ++j) {
                if(stars[i][j] && !visited[i][j]) {
                    search_from(i, j);
                    count++;
                }
            }
        }

        cout << "Case " << casenr << ": " << count << endl;
        casenr++;
    }
}