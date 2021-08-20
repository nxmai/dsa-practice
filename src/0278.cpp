#include <bits/stdc++.h>
using namespace std;

bool isBadVersion(int version);

int firstBadVersion(int n) {
    return fb(1,n);
}

int fb(int s, int e){
    if(s==e)
        return s;
    int mid=s+(e-s)/2;
    if(isBadVersion(mid))
        return fb(s,mid);
    return fb(mid+1,e);
}