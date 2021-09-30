#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    map<int, int> mp;
    int tmp;
    for(int i = 0; i < nums.size(); i++){
        tmp = target - nums[i];
        if(mp.find(tmp) != mp.end()){
            return {i, mp[tmp]};
        }
        mp[nums[i]]=i;
    }
    return {};
}