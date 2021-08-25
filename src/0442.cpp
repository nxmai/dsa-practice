#include <bits/stdc++.h>
using namespace std;


vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    vector<int> check(n+1, 0);
    vector<int> res;
    
    for(int i = 0; i < n; i++)
        check[nums[i]]++;
    
    for(int i = 0; i < check.size(); i++)
        if(check[i] == 2)
            res.push_back(i);
    
    return res;
}