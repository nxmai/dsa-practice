#include <bits/stdc++.h>
using namespace std;

bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    int m = ranges.size();
    map<int, int>check;
    
    for(int i = left; i <= right; i++){
        check[i] = 0;
    }
    
    for(int i = 0; i < m; i++){
        for(int j = ranges[i][0]; j <= ranges[i][1]; j++){
            if(j >= left && j <= right)
                check[j] = 1;
        }
    }
    
    for(map<int,int>::iterator i = check.begin(); i!= check.end(); i++){
        if(i->second == 0)
            return false;
    }
    return true;
}