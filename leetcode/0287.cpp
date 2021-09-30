#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    vector<bool> check(n, false);
    for(int i=0; i<n; ++i)
    {
        if(!check[nums[i]-1])
        {
            check[nums[i]-1] = true;
        }
        else
        {
            return nums[i];
        }
    }
    return 1;
}