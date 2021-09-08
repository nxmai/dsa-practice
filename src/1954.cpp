#include <bits/stdc++.h>
using namespace std;

 long long minimumPerimeter(long long neededApples) {
    long long n = 1, res;
    while(1){
        res = 2*n*(n+1)*(2*n + 1);
        if(res >= neededApples){
            break;
        }
        n++;
    }
    return n*8;
}