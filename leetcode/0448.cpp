#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    vector<int> check(n+1, 0);
    vector<int> res;
    
    for(int i = 0; i < nums.size(); i++){
        check[nums[i]] = 1;
    }
    
    for(int i = 1; i < check.size(); i++){
        if(check[i] == 0)
            res.push_back(i);
    }
    
    return res;
}