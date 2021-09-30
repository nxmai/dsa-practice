#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
    int l = s.length() - 1;
	int open = 0, close = 0;

	for (int i = 0; i <= l; i++) {
		if (s[i] == '*' || s[i] == '(')
			open++;
		else
			open--;

		if (s[l - i] == '*' || s[l - i] == ')')
			close++;
		else
			close--;

		if (open < 0 || close < 0)
			return false;
	}
	return true;
}