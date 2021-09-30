#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int res = 0, tmp = 0;
    int imin = 0, imax = 0;
    for(int i = 1; i < prices.size(); i++){
        if(prices[i] < prices[i-1]) {
            imin = i;
            imax = i;
            res += tmp;
            tmp = 0;
        }
        if(prices[i] > prices[imax])
            imax = i;
        
        tmp = max(tmp, prices[imax] - prices[imin]);
        
    }
    res += tmp;
    return res;
}