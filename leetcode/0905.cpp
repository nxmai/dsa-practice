#include <bits/stdc++.h>
using namespace std;

vector<int> sortArrayByParity(vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = n - 1;
    int tmp;
    
    while(i < j){
        if(nums[i] % 2 == 1 && nums[j] % 2 == 0){
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++; j--;
        }
        else if (nums[i] % 2 == 0 )
            i++;
        else
            j--;
    }
    
    return nums;
}