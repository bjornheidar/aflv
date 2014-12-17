//
//  main.cpp
//  ICanGuessTheDataStructure
//
//  Created by Einar Logi Hreinsson on 12/3/14.
//  Copyright (c) 2014 Einar Logi Hreinsson. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    
     cin.sync_with_stdio(false);
     cout.sync_with_stdio(false);
    
    
    while((!cin.eof())){
        int n = 0;
        cin >> n;
        
        if(cin.eof())return 0;
        
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        
        bool isStack = true;
        bool isQueue = true;
        bool isPQ = true;
        
        for(int i = 0; i < n; i++){
            
            
            int op;
            int val;
            cin >> op;
            cin >> val;
            if(op == 1){
                s.push(val);
                q.push(val);
                pq.push(val);
                
            }
            else if(op == 2){
                if(s.empty()||s.top() != val){
                    isStack = false;
                    
                    
                }
                if(q.empty() ||q.front() != val){
                    isQueue = false;
                    
                }
                if(pq.empty()||pq.top() != val){
                    isPQ = false;
                    
                }
                
                if(!s.empty()){
                s.pop();
                }
                if(!q.empty()){
                    q.pop();
                }

                if(!pq.empty()){
                    pq.pop();
                }

            }
            
           
        }
        if(!(isStack || isQueue || isPQ)){
            cout << "impossible" << endl;
        }
        else if (isStack && !(isQueue || isPQ)){
            cout << "stack" << endl;
        }
        else if(isQueue && !(isStack || isPQ)){
            cout << "queue" << endl;
        }
        else if(isPQ && !(isStack || isQueue)){
            cout << "priority queue" << endl;
        }
        else{
            cout << "not sure" << endl;
        }
    }
    
    
    
    return 0;
}
