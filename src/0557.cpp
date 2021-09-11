#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int i = 0, j = 0;
    for(; j<s.size(); j++){
        if(s[j] == ' '){
            reverse(s.begin() + i, s.begin() + j);
            i = j+1;
        }
    }
    reverse(s.begin() + i, s.begin() + j);
    return s;
}