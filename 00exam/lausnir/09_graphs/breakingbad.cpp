// Author: Ingólfur Halldórsson

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

unordered_map<string, int> groceries;
string groc2[100000];
vector<int> adj[100000];
vector<int> side(100000, -1);
bool is_bipartite = true;
void check_bipartite(int u)
{
    for(size_t i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(side[v] == -1)
        {
            side[v] = 1 - side[u];
            check_bipartite(v);
        }
        else if(side[u] == side[v])
        {
            is_bipartite = false;
        }
    }
}


int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        pair<string, int> prod;
        cin >> prod.first;
        prod.second = i;
        groceries.insert(prod);
        groc2[i] = prod.first;
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        string one, two;
        cin >> one >> two;
        adj[groceries[one]].push_back(groceries[two]);
        adj[groceries[two]].push_back(groceries[one]);
    }
    for(int u = 0; u < n; u++)
    {
        if(side[u] == -1)
        {
            side[u] = 0;
            check_bipartite(u);
        }
    }
    vector<string> heisenberg;
    vector<string> pinkman;
    if(!is_bipartite)
    {
        cout << "impossible";
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        if(side[i] == 0)
        {
            heisenberg.push_back(groc2[i]);
        }
        else
        {
            pinkman.push_back(groc2[i]);
        }
    }
    for(string s : heisenberg)
    {
        cout << s << " ";
    }
    cout << endl;
    for(string s : pinkman)
    {
        cout << s << " ";
    }
    return 0;
}
