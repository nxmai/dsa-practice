#include <bits/stdc++.h>
using namespace std;

int maxPower(string s) {
    int maxP = 1;
	int tmp = 1;
	int i = 1;

	while (i < s.length()) {
		if (s[i] == s[i - 1]) {
			tmp++;
            i++;
		}
		else {
			if (maxP < tmp) {
				maxP = tmp;
			}
				tmp = 1;
            i++;
		}
		
	}
        if (maxP < tmp) {
				maxP = tmp;
				tmp = 1;
			}
	return maxP;
}