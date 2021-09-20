#include <bits/stdc++.h>
using namespace std;

int staircase (vector<int>&dp, int n){
    if(n<0){
        return 0;
    }    
    else if(dp[n] != 0){
        return dp[n];
    }
    else {
        dp[n] = staircase(dp, n-1) + staircase(dp, n-2);
        return dp[n];
    }
}

int climbStairs(int n) {
    vector<int>dp(n+1);
    
    dp[0]=1;
    staircase(dp, n);
    return dp[n];
}