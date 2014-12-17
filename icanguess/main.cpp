#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int actions;
    while(cin >> actions){
        bool sta = true, que = true, pque = true;
        stack<int> s;
        queue<int> q;
        priority_queue<int> p;
        for (int i = 0; i < actions; ++i) {
            int op, e;
            cin >> op >> e;

            if(op == 1){
                s.push(e);
                q.push(e);
                p.push(e);
            }

            if(op == 2){
                int elem;
                if(s.size() > 0){
                    elem = s.top();
                    if(elem != e)
                        sta = false;
                    s.pop();
                }
                else
                    sta = false;
                if(q.size() > 0) {
                    elem = q.front();
                    if (elem != e)
                        que = false;
                    q.pop();
                }
                else
                    que = false;
                if(p.size() > 0) {
                    elem = p.top();
                    if (elem != e)
                        pque = false;
                    p.pop();
                }
                else
                    pque = false;
            }
        }

        string ans = "impossible";
        if(sta || que || pque){
            if((sta && que) || (sta && pque) || (que && pque))
                ans = "not sure";
            else if(sta)
                ans = "stack";
            else if(que)
                ans = "queue";
            else if(pque)
                ans = "priority queue";
        }

        cout << ans << endl;
    }
}