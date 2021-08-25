#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    long long lo = 0, hi = x/2 + 1, mid;
    
    while(lo <= hi){
        mid = (hi + lo)/2;
        
        if(mid*mid == x)
            return mid;
        if(mid*mid < x && (mid+1)*(mid+1) >x)
            return mid;
        if(mid*mid > x)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}