#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int tmp, i = n - 1;
    
    for(i; i>=0; i--){
        tmp = digits[i] + 1;
        if(tmp == 10){
            digits[i] = 0;
        } else {
            digits[i]+=1;
            break;
        }
    }
    if(i == -1 && tmp == 10){
        digits.insert(digits.begin(), 1);
    }
    
    return digits;
}