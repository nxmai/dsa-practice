#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    map<char, int>mp1;
    map<char, int>mp2;

    for (int i = 0; i < ransomNote.length(); i++) {
        mp1[ransomNote[i]]++;
    }
    for (int i = 0; i < magazine.length(); i++) {
        mp2[magazine[i]]++;
    }

    for (auto i : mp1) {
        if (mp2.find(i.first) == mp2.end() || mp2[i.first] < i.second)
            return false;
    }
    return true;  
}