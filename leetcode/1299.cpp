#include <bits/stdc++.h>
using namespace std;

vector<int> replaceElements(vector<int>& arr) {
    int n = arr.size() -1;
    int maxRight = -1;
    int tmp = arr[n];
    
    arr[n] = -1;
    for(int i = n - 1; i >= 0; i--){
        maxRight = max(maxRight, tmp);
        tmp = arr[i];
        arr[i] = maxRight;
    }
    return arr;
}   