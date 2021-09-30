//codeforces

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, s1;
    getline(cin, s);
    getline(cin, s1);

    string tmp = s;
    for(int i = s.length() - 1; i >=0; i--){
        if(s[i] == 'z'){
            s[i] = 'a';
            continue;
        }

        s[i] = s[i]+1;
        break;
    }

    if(s == s1)
        cout<< "No such string";
    else {
        cout << s;
    }
    

    return 0;
}