#include <bits/stdc++.h>
using namespace std;

int numJewelsInStones(string J, string S) {
    map<char, int>mp;
    for(int i=0;i<S.length();i++)
        mp[S[i]]++;
    
    int sum=0;
    
    map<char, int>::iterator it;
    for (int i = 0; i < J.length(); i++) {
        it = mp.find(J[i]);
        if (it != mp.end())
            sum += mp[J[i]];
    }
    
    return sum;
}