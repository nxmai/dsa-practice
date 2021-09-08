#include <bits/stdc++.h>
using namespace std;

int addRungs(vector<int>& rungs, int dist) {
    int res = 0;
    int n = rungs.size();
    int tmp;
    
    res += (rungs[0] - 1)/dist;
    
    for(int i = 0; i < n-1; i++){
        tmp = rungs[i+1]-rungs[i];
        
        if(tmp > dist){
            res += (tmp-1)/dist;
        }
    }
    return res;
}