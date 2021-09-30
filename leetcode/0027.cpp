#include<bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int res = 0;
    int poinVal = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val) {
            swap(nums[poinVal++], nums[i]);
            res++;
        }
    }

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    
    return res;
}