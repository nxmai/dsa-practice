#include <bits/stdc++.h>
using namespace std;

vector<string>res;
    
void backtrack(string s, string s1, int start){
    res.push_back(s1);
    for(int i = start; i < s.length(); i++){
        if(s[i] >= 'a' && s[i] <='z'){
            s1[i] = s[i] - 32;
            backtrack(s, s1, i+1);
            s1[i] = s[i];
        } else if(s[i] >= 'A' && s[i] <='Z'){
            s1[i] = s[i] + 32;
            backtrack(s, s1, i+1);
            s1[i] = s[i];
        }
    }
}

vector<string> letterCasePermutation(string s) {
    backtrack(s, s, 0);
    return res;
}