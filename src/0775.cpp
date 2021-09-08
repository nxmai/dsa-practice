#include <bits/stdc++.h>
using namespace std;

bool isIdealPermutation(vector<int>& A) {
    if(A.size() == 1 || A.size() == 2)
        return true;
    
    int maxNum = -1;
    for(int i=0; i<A.size()-2; i++){
        maxNum = max(A[i], maxNum);
        if(maxNum > A[i+2]){
            return false;
        }
    }
    return true;
}