#include <bits/stdc++.h>
using namespace std;

bool makeEqual(vector<string>& words) {
    int n = words.size();
    map<char,int>mp;
    
    for(int i = 0; i < words.size(); i++){
        for(int j = 0; j < words[i].size(); j++){
            mp[words[i][j]]++;
        }
    }
    
    for(map<char,int>::iterator i=mp.begin(); i != mp.end(); i++){
        if(i->second % n != 0)
            return false;
    }
    
    return true;
}