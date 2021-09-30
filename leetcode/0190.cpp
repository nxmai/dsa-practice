#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    unsigned int ans = 0;
    int s = 32;
    
    if(n==0)
        return n;
    
    while(n!=0){
        ans <<= 1;
        if(n & 1 == 1){
            ans ^= 1;
        }
        n >>= 1;
        s--;
    }
    if(s>0)
        ans <<= s;
    return ans;
}