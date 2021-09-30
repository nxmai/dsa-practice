#include <bits/stdc++.h>
using namespace std;

string reversePrefix(string word, char ch) {
    int i;
    int n = word.length();
    
    for(i = 0; i < n; i++){
        if(word[i] == ch){
            break;
        }
    }
    if(i!=n)
        reverse(word.begin(), word.begin()+i+1);
    
    return word;
}