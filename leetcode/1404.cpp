#include <bits/stdc++.h>
using namespace std;

int numSteps(string s) {
        int res = 0;
	if (s == "1")
		return 0;

	int len = s.length() - 1;
	int i;
	while (len > 0)
	{
		res++;
		if (s[len] == '1') {
			i = len;
			while (i >= 0 && s[i] == '1')
				s[i--] = '0';

			if (i >= 0)
				s[i] = '1';
			else {
				s = "1" + s;
				len++;
			}
		}
		else
			len--;
	}
	return res;
}