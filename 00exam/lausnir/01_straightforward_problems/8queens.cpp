// Author: Björn Heiðar Rúnarsson

#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main() {
    string rows[8];
    int qpos[8];
    bool valid = true;

    for (int i = 0; i < 8; ++i) {
        getline(cin, rows[i]);
        //Does the row have a queen? Or to many? or a queen in the same column?
        int queens = 0;
        for (int j = 0; j < 8; ++j) {
            if (rows[i][j] == '*') {
                queens++;

                //Check for queen in the same column
                qpos[i] = j;
                for (int k = 0; k < i; ++k) {
                    if (qpos[k] == j) {
                        valid = false;
                    }
                }
            }
        }
        if(queens != 1) {
            valid = false;
        }
    }
    //1 queen each row and column verified
    if(valid){
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if(i != j){
                    if(abs(qpos[i] - qpos[j]) == abs(i - j))
                        valid = false;
                }
            }
        }
    }

    if(valid)
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;

    return 0;
};
