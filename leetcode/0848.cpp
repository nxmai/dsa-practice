#include <bits/stdc++.h>
using namespace std;

string shiftingLetters(string s, vector<int>& shifts) {
    int n = shifts.size();
    int cur = 0;
    for(int i = n - 1; i >= 0; i--){
        cur += shifts[i];
        cur %= 26;
        shifts[i] = cur;
    }
    
    int c;
    for(int i = 0; i < n; i++){
        c = s[i] - 'a';
        c = (c + shifts[i]) % 26;
        s[i] = 'a' + c;
    }
    
    return s;
}