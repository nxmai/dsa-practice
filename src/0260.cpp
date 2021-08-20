#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    map<int, int> mp;
    for(int i = 0; i < nums.size(); i++){
        mp[nums[i]]++;
    }
    
    vector<int> res;
    
    for(map<int,int>::iterator i = mp.begin(); i != mp.end(); i++){
        if(i->second == 1)
            res.push_back(i->first);
    }
    
    return res;
}