#include <bits/stdc++.h>
using namespace std;

 int getLucky(string s, int k) {
    string strNum = "";
    for(int i = 0; i < s.length(); i++){
        strNum += to_string((int)s[i] - 96);
    }
    
    int tmp = 0;
    for(int i = 0; i < k; i++){
        tmp = 0;
        for(int i = 0; i < strNum.length(); i++){
            tmp += ((int)strNum[i] - 48);
        }
        strNum = to_string(tmp);
    }
    
    // stringstream geek(tmp);
    // int x = 0;
    // geek >> x;
    
    return tmp;
}