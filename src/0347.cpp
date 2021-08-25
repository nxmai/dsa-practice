#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int>mp;
    vector<int> res;

    for(int i = 0; i < nums.size(); i++)
        mp[nums[i]]++;

    vector<pair<int, int>> vt;

    for (auto& it : mp) {
        vt.push_back(it);
    }

    sort(vt.begin(), vt.end(), cmp);

    for (auto& it : vt) {
        if(k==0)
            break;
        
        res.push_back(it.first);
        k--;
    }

    return res; 
}