#include <bits/stdc++.h>
using namespace std;

int canBeTypedWords(string text, string broken) {
    vector<int>check(26, 0);
    
    for(int i = 0; i < broken.length(); i++){
        check[(int)broken[i] - 97] = 1;
    }
    
    int i = 0;
    int flag = 1;
    int res = 0;
    
    while(i < text.length()){
        while(i < text.length() && text[i] != ' '){
            if(check[((int)text[i]) - 97] == 1){
                flag = 0;
            }
            i++;
        }
        if(flag == 1){
            res++;
        }
        flag = 1;
        i++;
    }
    
    return res;
}