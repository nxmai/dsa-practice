#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    map<int,int>::iterator it;
    int max=0;
    
    for(map<int,int>::iterator i =mp.begin(); i!=mp.end();i++){
        if(max<i->second)
        {
            max=i->second;
            it=i;
        }
    }
    return it->first;
}