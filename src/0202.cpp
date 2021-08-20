#include <bits/stdc++.h>
using namespace std;

int num(int n)
{
    int res = 0;
    while (n != 0) {
        res += pow(n % 10, 2);
        n /= 10;
    }
    return res;
}

bool isHappy(int n) {
    set<int>st;

    while (1) {
        st.insert(n);
        n = num(n);
        if (n == 1)
            return true;
        if (st.find(n) != st.end())
            return false;
    }
}