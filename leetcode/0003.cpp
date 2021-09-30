#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    set<char>st;
    int res=0;
    int i=0,j=0;
    int n=s.length();
    
    while(i<n && j<n){
        if(st.find(s[j]) == st.end()){
            st.insert(s[j]);
            j++;
            res=max(res,j-i);
        } else {
            st.erase(s[i]);
            i++;
        }
    }
    return res;
}