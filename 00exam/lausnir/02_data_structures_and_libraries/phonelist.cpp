// Author: Sævar Örn Kjartansson

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int t, n;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        string *v = new string[n];

        string number;

        for (int j = 0; j < n; j++)
        {
            cin >> number;
            v[j] = number;
        }

        sort(v, v+n);

        int j;
        for (j = 1; j < n; j++)
        {
            if (!v[j].compare(0, min(v[j].length(), v[j-1].length()), v[j-1]))
            {
                cout << "NO" << endl;
                break;
            }
        }
        if (j == n)
            cout << "YES" << endl;
    }
}
