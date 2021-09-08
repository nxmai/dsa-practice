#include <bits/stdc++.h>
using namespace std;

int removePalindromeSub(string s) {
    if(s=="")
        return 0;
    string s1 = s;
    reverse(s.begin(), s.end());
    if(s==s1){
        return 1;
    } 
    return 2;
}