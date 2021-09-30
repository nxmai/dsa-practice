#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    for(int i =0; i<s.length(); i++){
        s[i] = (tolower(s[i]));
    }
    
    int i=0, j=s.length() -1;
    
    while(i<j){
        if(!((s[i]>='a' && s[i] <= 'z') || (s[i]>='0' && s[i] <= '9'))) i++;
        else if(!((s[j]>='a' && s[j] <= 'z') || (s[j]>='0' && s[j] <= '9'))) j--;
        else {
            if(s[i]!=s[j]) return false;
            else {
                i++;j--;
            }
        }
    }
    return true;
}