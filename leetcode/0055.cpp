#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int tmp = 0;
    for(int i = 0; i < nums.size(); i++){
        if(i > tmp)
            return false;
        tmp = max(tmp, i + nums[i]);
    }
    return true;
}
