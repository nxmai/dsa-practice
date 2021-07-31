#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int>v;
    int minValue = INT_MAX;
    
    MinStack() {
        
    }
    
    void push(int x) {
        v.push_back(x);
        if(minValue>x)
            minValue=x;
    }
    
    void pop() {
        if(v[v.size()-1]==minValue)
        {
            minValue=INT_MAX;
            for(int i=0;i<v.size()-1;i++){
                if(minValue>v[i])
                    minValue=v[i];
            }
        }
        v.pop_back();
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        return minValue;
    }
};