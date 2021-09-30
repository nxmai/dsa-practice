#include <bits/stdc++.h>
using namespace std;

int minOperations(int n) {
        int mid = ((n-1)*2)/2 + 1;
        
        return mid*(n/2) - (n/2)*(n/2);
}
