#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int XOR = 0, missing = 0;
    for(int i=0;i<nums.size();i++){
        XOR^=nums[i];
        missing^=i;
    }
    missing^=nums.size();
    
    return missing^XOR;
}