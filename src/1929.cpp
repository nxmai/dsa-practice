#include <bits/stdc++.h>
using namespace std;

vector<int> getConcatenation(vector<int>& nums) {
    vector<int>res = nums;
    for(int i = 0; i<nums.size(); i++)
        res.push_back(nums[i]);
    return res;
}