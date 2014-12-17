// Author: Arnar Kári Ágústsson

#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;



const int NUMBER = 47;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
 
    int ts;
    cin >> ts;
    for (int t = 0; t < ts; t++) {
        
        int n;
        cin >> n;
        
        int sum = 0;
        long long subsequences = 0;
        
        map<int, int> map;
        vector<int> v;
        
        for (int i = 0 ; i < n; i++) {
            int num;
            cin >> num;
            
            sum += num;
            v.push_back(sum);
        }
        
        for (int i = 0; i < n; i++) {

            if (v[i] == NUMBER){
                subsequences++;
            }
            
            subsequences += map[v[i] - NUMBER];
            map[v[i]]++;
        }
        
        cout << subsequences << endl;
    }
    return 0;
}
