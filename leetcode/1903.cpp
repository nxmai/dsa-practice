#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
    int i = num.length() - 1;
    
    for(i; i >= 0; i--){
        if(num[i] == '0' || num[i] == '2' || num[i] == '4' || num[i] == '6' || num[i] == '8'){
            continue;
        }
        break;
    }
    
    string res = num.substr(0, i+1);
    return res;
}