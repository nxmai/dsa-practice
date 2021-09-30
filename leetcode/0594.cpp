#include <bits/stdc++.h>
using namespace std;

// int findLHS(vector<int>& nums) {
//     int m = 0;
//     unordered_map<int, int> counter;
    
//     for (int n : nums) ++counter[n];

//     for (auto const& [key, val] : counter)
//     if (counter.find(key - 1) != counter.end())
//         m = max(val + counter[key - 1], m);
        
//     return m;
// }