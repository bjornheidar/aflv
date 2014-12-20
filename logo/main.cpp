#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

#define PI atan(1)*4
double degToRad(int deg){
    return (deg * PI/180);
}

int calc_dist(double x, double y){
    return static_cast<int>(round(sqrt(x*x + y*y)));
}

int main() {
    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; ++i) {
        int cmds;
        cin >> cmds;

        double x,y;  x = y = 0.0;
        int heading = 0;
        for (int j = 0; j < cmds; ++j) {
            string cmd;
            int amount;
            cin >> cmd >> amount;

            switch(cmd[0]){
                case 'b':
                    amount *= -1;
                case 'f':
                    x += amount * cos(degToRad(heading));
                    y += amount * sin(degToRad(heading));
                    break;
                case 'r':
                    amount *= -1;
                case 'l':
                    heading += amount;

                    while(heading < 0)
                        heading = 360 + heading;
                    if(heading > 359)
                        heading = heading % 360;

                    break;
            }
        }

        cout << calc_dist(x, y) << endl;
    }
}