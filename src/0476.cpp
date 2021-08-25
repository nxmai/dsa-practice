#include <bits/stdc++.h>
using namespace std;

int findComplement(int num) {
    int count=0;
    int j=num;
    while(j!=0){
        j=j/2;
        count++;
    }
    int ans = pow(2,count) - 1;
    return num ^ ans;
}