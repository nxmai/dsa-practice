#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<double>vt(amount+1, INT_MAX);
    vt[0]=0;
    
    for(int i=1;i<=amount;i++){
        for(int coin: coins){
            if(coin<=i){
                vt[i]=min(vt[i], vt[i-coin] +1);
            }
        }
    }
    return vt[amount] == INT_MAX ? -1 : vt[amount];
}