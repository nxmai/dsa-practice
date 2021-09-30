#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    map<char, int>mp;
    
    mp.insert(pair<char, int>('I', 1));
    mp.insert(pair<char, int>('V', 5));
    mp.insert(pair<char, int>('X', 10));
    mp.insert(pair<char, int>('L', 50));
    mp.insert(pair<char, int>('C', 100));
    mp.insert(pair<char, int>('D', 500));
    mp.insert(pair<char, int>('M', 1000));
    
    int i = s.length() - 1;
    int res = mp[s[i]];
    for(i = s.length() - 2; i >= 0; i--){
        if(mp[s[i]] < mp[s[i+1]]){
            res -= mp[s[i]];
        } else {
            res += mp[s[i]];
        }
    }
    
    return res;
    
}