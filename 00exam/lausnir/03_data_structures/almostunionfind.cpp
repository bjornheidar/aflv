// Author: Ingibergur Sindri Stefnisson

#include<iostream>
#include<stdio.h>

#include<map>
using namespace std;
struct union_find {
    int* parent, *sz, *sum, *id;
    int nn;
    union_find(int n) {
        parent = new int[n*2];
        sz = new int[n*2];
        sum = new int[n*2];
        id = new int[n*2];
        nn = n+1;
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            sz[i] = 1;
            sum[i] = i;
            id[i] = i;
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
        int rootX = find(id[x]);
        int rootY = find(id[y]);
        if(rootX == rootY)
            return;
        parent[rootX] = rootY;
        sz[rootY] += sz[rootX];
        sum[rootY] += sum[rootX];
        //printf("sizex: %d, sizey: %d", sz[rootX], sz[rootY]);
    }
    void remove(int x)
    {
        int rootX = find(id[x]);
        sum[rootX] -= x;
        sz[rootX]--;
        id[x] = ++nn;
        sum[id[x]] = x;
        sz[id[x]] = 1;
        parent[id[x]] = id[x];
    }
    bool connected(int x, int y)    {
        return find(id[x]) == find(id[y]);
    }
    int sizes(int x)
    {
        return sz[find(id[x])];
    }
    int sums(int x)
    {
        return sum[find(id[x])];
    }
};
int main(){
    int n = 0,m =0;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        if(n == 0)
            break;
        union_find uf(n);
        for(int i = 0; i < m ; i++)
        {
            int a = 0,b = 0,c = 0;
            scanf("%d", &a);
            switch(a){
                case 1:
                    scanf("%d %d", &b,&c);
                    uf.unite(b,c);
                    break;
                case 2:
                    scanf("%d %d", &b,&c);
                    if(uf.connected(b,c) == false)
                    {
                        uf.remove(b);
                        uf.unite(b,c);
                    }
                    break;
                case 3:
                    scanf("%d", &b);
                    printf("%d %d\n",uf.sizes(b), uf.sums(b));
                    break;
            }

        }
    }


    return 0;
}
