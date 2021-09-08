#include <bits/stdc++.h>
using namespace std;

bool isThree(int n) {
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(n%i==0)
            cnt++;
        if(cnt >= 4){
            return false;
        }
    }
    
    if(cnt == 3){
        return true;
    }
    
    return false;
}