#include <bits/stdc++.h>
using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> res;
    for(int i = 1; i<=n ;i++){
        res.push_back(to_string(i));
    }
    
    for(int i=2; i<n;i+=3){
        res[i]="Fizz";
    }
    
    for(int i=4;i<n;i+=5){
        res[i]="Buzz";
    }
    
    for(int i =14;i<n;i+=15){
        res[i]="FizzBuzz";
    }
    return res;
}