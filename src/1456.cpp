#include <bits/stdc++.h>
using namespace std;

int check(char i) {
	if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
		return 1;
	}
	return 0;
}
    
int maxVowels(string s, int k) {
    int tmp = 0;

for (int i = 0; i < k; i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
        tmp += 1;
    }
}

int res = tmp;
int num;
for (int i = 1; i < s.length() - (k - 1); i++) {
    res = max(res, max(tmp, tmp + check(s[i + k - 1]) - check(s[i - 1])));
    tmp = tmp + check(s[i + k - 1]) - check(s[i - 1]);
}
return res;
}