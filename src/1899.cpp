#include <bits/stdc++.h>
using namespace std;

bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    vector<int>res(3, 0);
    
    for (auto s : triplets)
        if (s[0] <= target[0] && s[1] <= target[1] && s[2] <= target[2])
            res = { max(res[0], s[0]), max(res[1], s[1]), max(res[2], s[2]) };
    return res == target;
}