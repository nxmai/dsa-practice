#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    vector<string>v;
    istringstream ss(path);
    string token, res;
    
    while(getline(ss, token, '/')){
        if(token=="" || token ==".") continue;
        if(token!="..") v.emplace_back(token);
        else if (!v.empty()) v.pop_back();
    }
    
    for(auto i:v) res +="/"+i;
    return v.empty() ? "/" : res;
}