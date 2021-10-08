#include <iostream>
#include <vector>

using namespace std;

 vector<int> findAnagrams(string s, string p) {
    vector<int>freP(26, 0);
    
    for(int i = 0; i < p.length(); i++){
        freP[p[i] - 'a']++;
    }
    
    vector<int>tmp(26, 0);
    vector<int>res;
    int i = 0, j = 0;
    
    while(j < s.length()){
        tmp[s[j] - 'a']++;
        
        if((j-i+1) == p.length()){
            if(tmp == freP){
                res.push_back(i);
            }
            tmp[s[i] - 'a']--;
            i++;
        }
        j++;
    }
    return res;        
}