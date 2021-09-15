#include <bits/stdc++.h>
using namespace std;

long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    unordered_map<double, int>mp;
    int n = rectangles.size();
    
    for(int i = 0; i < n; i++){
        double ratio = (double)rectangles[i][0] / rectangles[i][1];
        mp[ratio]++;
    }
    
    long long ans = 0;
    for (auto x : mp)
    {
        long long value = x.second;
        if (value > 1)
        {
            ans += (value * (value - 1)) / 2;
        }
    }
    return ans;
}