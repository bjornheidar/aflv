// Author: Björn Ingi Baldvinsson

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct segment_tree {
    segment_tree *left, *right;
    int from, to, value;
    segment_tree(int from, int to)
        : left(NULL), right(NULL), from(from), to(to), value(0) { }
};
segment_tree* build(const vector<int> &arr, int l, int r) {
    if (l > r) return NULL;
    segment_tree *res = new segment_tree(l, r);
    if (l == r) {
        res->value = arr[l];
    } else {
        int m = (l + r) / 2;
        res->left = build(arr, l, m);
        res->right = build(arr, m + 1, r);
        if (res->left != NULL) res->value = res->left->value;
        if (res->right != NULL)
            if(res->value < res->right->value) res->value = res->right->value;
    }
    return res;
}

int query(segment_tree *tree, int l, int r) {
    if (tree == NULL) return 0;
    if (l <= tree->from && tree->to <= r) return tree->value;
    if (tree->to < l) return 0;
    if (r < tree->from) return 0;
    return max(query(tree->left, l, r), query(tree->right, l, r));
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n;
    while(cin >> n && n != 0)
    {
        map<int, int> *yidx = new map<int, int>();
        vector<int> rain(n); //= new vector<int>(n);

        for(int i = 0; i < n; i++)
        {
            int y, r;
            cin >> y >> r;

            rain[i] = r;
            yidx->insert(pair<int, int>(y, i));
            //cout << y << ": " << yidx->at(y) << endl;
        }

        segment_tree *tree = build(rain, 0, n - 1);

        int m;
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            int y, x;
            cin >> y >> x;

            map<int, int>::iterator r_it = yidx->lower_bound(x);

            // x is <= smallest year
            if(r_it == yidx->begin())
            {
                cout << "maybe" << endl;
                continue;
            }

            map<int, int>::iterator l_it = yidx->lower_bound(y);

            // y is > biggest year
            if(l_it == yidx->end())
            {
                cout << "maybe" << endl;
                continue;
            }

            // x is > biggest year
            if(r_it == yidx->end() || r_it->first != x)
            {
                r_it--;
            }

            // x might now be = y
            if(r_it == l_it)
            {
                cout << "maybe" << endl;
                continue;
            }

            // x and y rain is not recorded
            if(l_it->first != y && r_it->first != x)
            {
                cout << "maybe" << endl;
                continue;
            }

            if(l_it->first != y)
            {
                int maxy = query(tree, l_it->second, r_it->second - 1);
                if(rain[r_it->second] > maxy)
                {
                    cout << "maybe" << endl;
                }
                else
                {
                    cout << "false" << endl;
                }
                continue;
            }

            if(r_it->first != x)
            {
                int maxx = query(tree, l_it->second + 1, r_it->second);
                if(rain[l_it->second] > maxx)
                {
                    cout << "maybe" << endl;
                }
                else
                {
                    cout << "false" << endl;
                }
                continue;
            }

            //int max = query()

            int l = l_it->second;
            int r = r_it->second;

            int ydiff = x - y;
            if(ydiff < 0) ydiff *= -1;
            if((r - l) == ydiff)
            {
                if(ydiff > 1)
                {
                    if(query(tree, l + 1, r - 1) < rain[r] && rain[l] >= rain[r])
                    {
                        cout << "true" << endl;
                    }
                    else{ cout << "false" << endl;}
                }
                else
                {
                    if(rain[l] >= rain[r]) cout << "true" << endl;
                    else cout << "false" << endl;
                }
            }
            else
            {
                if((r - l) == 1)
                {
                    if(rain[l] >= rain[r])
                        cout << "maybe" << endl;
                    else
                        cout << "false" << endl;
                }
                else if(query(tree, l + 1, r - 1) < rain[r] && rain[l] >= rain[r])
                {
                    cout << "maybe" << endl;
                }
                else{ cout << "false" << endl;}
            }
        }
        cout << endl;
    }

    return 0;
}
