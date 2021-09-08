#include <bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part) {
    int flag = 0;
    
    while(1){
        string::size_type i = s.find(part);

        if (i != string::npos){
            s.erase(i, part.length());
        } else {
            break;
        }
    }
    
    return s;
}