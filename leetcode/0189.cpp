#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int count = 0, n = nums.size();
    k = k % n;
    int cur, prev, next, temp;
    for(int start = 0; count < n; start++){
        cur = start;
        prev = nums[cur];
        
        do {
            next = (cur + k) % n;
            temp = nums[next];
            nums[next] = prev;
            prev = temp;
            cur = next;
            count++;
        } while(start != cur);
    }
    
}