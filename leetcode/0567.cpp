#include <bits/stdc++.h>
using namespace std;

bool matches(vector<int>t1, vector<int>t2){
    for(int j = 0; j < 26; j++){
        if(t1[j] != t2[j]){
            return false;
        }
    }    
    return true;
}
bool checkInclusion(string s1, string s2) {
    vector<int>vt(26, 0);
    for(int i = 0; i < s1.length(); i++){
        vt[s1[i] - 'a']++; 
    }
    int n = s2.length();
    int n1 = s1.length();
    
    for(int i = 0; i <= n - n1; i++){
        vector<int>t2(26, 0);
        for(int j = 0; j < n1; j++){
            t2[s2[i + j] - 'a']++;
        }
        if(matches(vt, t2))
            return true;
    }
    return false;
}