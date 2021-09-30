#include <bits/stdc++.h>
using namespace std;

int finalValueAfterOperations(vector<string>& ope) {
    int res = 0;
    for(int i = 0; i < ope.size(); i++){
        if(ope[i] == "++X" || ope[i] == "X++")
            res++;
        if(ope[i] == "--X" || ope[i] == "X--")
            res--;
    }
    return res;
}