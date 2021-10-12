//codeforces

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int res=0;
    char prev = 'a';

    for(int i = 0; i < s.length(); i++){
        if(prev > s[i]){
            res += min( abs((int)prev - (int)s[i]), abs((int)prev - 26 - (int)s[i]) );
        } else {
            res += min( abs((int)prev - (int)s[i]), abs((int)prev + 26 - (int)s[i]) );
        }
        
        prev = s[i];
    }

    cout<<res;

    return 0;
}