#include <bits/stdc++.h>
using namespace std;

int subtractProductAndSum(int n) {
    int product=1, sum=0, r=0;
    while( n>0 ){
        r = n%10;
        product *= r;
        sum += r;
        n /= 10;
    }
    return product - sum;
}