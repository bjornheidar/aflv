#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

vector<int> adj[1000];
vector<bool> visited(1000, false);
vector<int> order;

void topsort(int u) {
    if (visited[u]) {
        return;
    }
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        topsort(v);
    }
    order.push_back(u);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; ++i) {
        int A, B;
        scanf("%d %d", &A, &B);

        adj[A].push_back(B);
    }

    for (int j = 0; j < N; ++j) {
        topsort(j);
    }

    //check if ok
    if(order.size() != N) {
        printf("back to the lab\n");
        return 0;
    }

    for (vector<int>::reverse_iterator it = order.rbegin(); it != order.rend()-1; it++) {
        int u = *it;
        bool found = false;
        for (int j = 0; j < adj[u].size(); ++j) {
            if (adj[u][j] == *(it+1)) {
                found = true;
                break;
            }
        }
        if(!found){
            printf("back to the lab");
            return 0;
        }
    }

    for(vector<int>::reverse_iterator it = order.rbegin(); it != order.rend(); it++){
        printf("%d ", *it);
    }

    //Cases
    //check for uniqueness
    /*bool not_unique = false;
    for(vector<int>::reverse_iterator it = order.rbegin(); it != order.rend()-1; ++it){
        int u = *it, v = *(it+1);
        bool found = false;
        for (int i = 0; i < adj[u].size(); ++i) {
            if(adj[u][i] == v){
                found = true;
                break;
            }
        }
        if(!found){
            not_unique = true;
            break;
        }
    }
    //Not all can be sorted or it is not unique
    if(order.size() != N || not_unique ){
        printf("back to the lab\n");
    }
    //All good
    else {
        for (vector<int>::reverse_iterator it = order.rbegin(); it != order.rend(); it++) {
            printf("%d ", *it);
        }
        printf("\n");
    }*/

    return 0;
}