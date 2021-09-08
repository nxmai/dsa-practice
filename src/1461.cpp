#include <bits/stdc++.h>
using namespace std;

bool hasAllCodes(string s, int k) {
    if(k>s.length())
        return false;
    
    int size = 1 << k;
    set<string>st;
    string tmp;
    for(int i=0;i<=s.length()-k;i++){
        tmp = s.substr(i, k);
        if(st.find(tmp) == st.end()){
            st.insert(tmp);
            size--;
            if(size==0){
                return true;
            }
        }
    }
    return false;
}