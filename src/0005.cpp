#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    int n = s.length() - 1;
    int left, right, st, e;
    int res=0;
    string ans="";
    
    for(int i =0; i<=n; i++){
        left=i; right=i;
        while(left>=0 && right <= n && s[left] == s[right]){
            
            if(right-left+1 > res){
                res=right-left+1;
                st=left; e=right;
            }
            
            left--; right++;
        }
    }
    
    for(int i =0; i<n;i++){
        left=i;
        right=i+1;
        while(left>=0 && right <= n && s[left] == s[right]){
            
            if(right-left+1 > res){
                res=right-left+1;
                st=left; e=right;
            }
            
            left--; right++;
        }
    }
    for(int i=st; i<=e; i++)
        ans+=s[i];
    return ans;
}