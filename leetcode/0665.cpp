#include <bits/stdc++.h>
using namespace std;

 bool checkPossibility(vector<int>& nums) {
    int count = 0;
    int i;
    for(i = 0; i < nums.size() - 1; i++){
        if(nums[i] > nums[i+1]){
            count++;
            if (i>= 1 && i < nums.size() - 2 && nums[i] > nums[i+2] && nums[i-1] > nums[i+1])
                return false;
        }
    }
    
    if(count >= 2)
        return false;
    return true;
}