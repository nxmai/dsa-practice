#include <bits/stdc++.h>
using namespace std;

int chalkReplacer(vector<int>& chalk, int k) {
    long long int sumChalk = 0;
    for(int i = 0; i < chalk.size(); i++){
        sumChalk += chalk[i];
    }
    
    int tmp = k - (k/sumChalk)*sumChalk;
    
    for(int i = 0; i < chalk.size(); i++){
        if(tmp < chalk[i])
            return i;
        tmp -= chalk[i];
    }
    
    return 0;
}