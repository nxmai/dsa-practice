#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>>res;
    int i = 0, j = 0;
    
    while(i < A.size() && j < B.size()){
        int lo = max(A[i][0], B[j][0]);
        int hi = min(A[i][1], B[j][1]);
        
        if(lo <= hi){
            res.push_back({lo, hi});
        }
        
        if(A[i][1] < B[j][1]){
            i++;
        } else{
            j++;
        }
    }
    
    return res;
}