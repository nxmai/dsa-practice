#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() -1;
    int res = 0;
    
    while(left<right){
        res = max((right - left) * min(height[right], height[left]), res);
        if(height[left] < height[right])
            left++;
        else
            right--;
    }
    return res;
}