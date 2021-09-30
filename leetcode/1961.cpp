#include <bits/stdc++.h>
using namespace std;

bool isPrefixString(string s, vector<string>& words) {
    bool ans = true;
    int cnt=0;
    string str = "";
    for(int i = 0; i < words.size(); i++){
        cnt += words[i].size();
        string tmp = s.substr(0, cnt);
        str += words[i];
        
        if(tmp != str){
            ans = false;
            break;
        }
        if(str == s){
            break;
        }
    }
    if(cnt != s.length()){
        ans = false;
    }
    
    return ans;
}