#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int n = nums.size();
    map<int, int> mp;
    
    for(int i = 0; i < n; i++){
        mp[nums[i]]++;
    }
    
    int res;
    for(map<int, int>::iterator i = mp.begin(); i != mp.end(); i++){
        if(i->second == 1){
            res = i->first;
            break;
        }
    }
    
    return res;
}