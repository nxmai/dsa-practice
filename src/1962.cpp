#include <bits/stdc++.h>
using namespace std;

int minStoneSum(vector<int>& piles, int k) {
    priority_queue<int>q;
    
    for(int i = 0; i < piles.size(); i++){
        q.push(piles[i]);
    }
    
    int top;
    while(k!=0){
        top = q.top();
        q.pop();
        top = ceil(top*1.0/2);
        q.push(top);
        
        k--;
    }
    
    int ans = 0;
    while(!q.empty()){
        ans += q.top();
        q.pop();
    }
    
    return ans;
}