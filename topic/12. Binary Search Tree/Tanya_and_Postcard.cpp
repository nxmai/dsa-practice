//codeforces
#include <iostream>
#include <map>

using namespace std;

int main() {
    string s, t;
    map<char, int>a, b;
    cin >> s;
    cin >> t;

    int ycnt = 0;
    int wcnt = 0;

    for(int i = 0; i < t.length(); i++){
        int id = t[i] - 'A';
        if(t[i] > 'Z')
            id = t[i] - 'a' + 26;
        a[id]++;
    }

    for(int i = 0; i < s.length(); i++){
        int id = s[i] - 'A';
        if(s[i] > 'Z')
            id = s[i] - 'a' + 26;
        b[id]++;
    }

    for(int i = 0; i < 52; i++){
        int tmp = min(a[i], b[i]);
        ycnt += tmp;
        a[i] -= tmp;
        b[i] -= tmp;
    }

    for(int i = 0; i < 52; i++){
        wcnt += min(a[i], b[i+26]) + min(a[i+26], b[i]);
    }
    
    cout << ycnt << " " << wcnt << endl;

    return 0;
}