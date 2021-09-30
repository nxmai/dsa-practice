#include <bits/stdc++.h>
using namespace std;

int rangeBitwiseAnd(int m, int n) {
    while(n>m)
        n=n&n-1;
    return n&m;

}