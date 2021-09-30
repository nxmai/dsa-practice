#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int i = 0, j = 0;
    int n = nums.size() - 1;
    while(i < n && j < n){
        while(i < n && nums[i] != 0){
            i++;
        }
        while(j < n && !(nums[j] != 0 && j > i)){
            j++;
        }
        swap(nums[i], nums[j]);
    }
}