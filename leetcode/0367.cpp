#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int num) {
    int r=sqrt(num);
    if(r*r==num)
        return true;
    return false;
}