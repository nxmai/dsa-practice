#include<bits/stdc++.h>
using namespace std;

int find(vector<int>nums, int target, int flag){
        int n = nums.size();
        int l = 0, r = n - 1, mid;
        int res = -1;
        
        while(l <= r){
            mid = (l+r)/2;
            if(nums[mid] == target){
                res = mid;
                (flag == 0) ? r = mid - 1 : l = mid + 1;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        
        return res;
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>{find(nums, target, 0), find(nums, target, 1)};        
    }