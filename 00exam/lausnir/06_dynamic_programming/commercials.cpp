// Author: Jóhann Örn Bjarkason

#include <iostream>
#include <cstring>
using namespace std;

int arr[100000];
int mem[100000];
bool comp[100000];

int max_profit(int i)
{
    if (i == 0)
    {
        return arr[i];
    }
    if (comp[i])
    {
        return mem[i];
    }
    int res = max(arr[i], arr[i] + max_profit(i - 1));
    mem[i] = res;
    comp[i] = true;
    return res;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int N, P, students;
    cin >> N >> P;
    for(int i = 0; i < N; i++)
    {
        cin >> students;
        arr[i] = students - P;
    }
    memset(comp, 0, sizeof(comp));
    int maximum = 0;
    for(int i = 0; i < N; i++)
    {
        maximum = max(maximum, max_profit(i));
    }
    cout << maximum;
    return 0;
}
