#include <bits/stdc++.h>
using namespace std;

bool areOccurrencesEqual(string s) {
    vector<int>vt(26, 0);
    
    for(int i = 0; i < s.length(); i++){
        vt[(int)s[i] - 97]++;
    }
    
    set<int> st;
    for(int i = 0; i < vt.size() - 1; i++){
        if(vt[i] != 0){
            st.insert(vt[i]);
        }
    }
    
    if(st.size() != 1){
        return false;
    }
    return true;
}