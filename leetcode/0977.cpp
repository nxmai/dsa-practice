#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int>res(n);
    int l = 0, r = n - 1, k = n - 1;
    while(l <= r){
        if(abs(nums[l]) > abs(nums[r])){
            res[k--] = nums[l] * nums[l];
            l++;
        } else{
            res[k--] = nums[r] * nums[r];
            r--;
        }
    }
    
    return res;
}