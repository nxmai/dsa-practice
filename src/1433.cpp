#include <bits/stdc++.h>
using namespace std;

bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	int i = 0;
	int n = s1.length();
	int flag = 2;
	while (i < n && s1[i] == s2[i])
		i++;
	if (i < n && s1[i] < s2[i])
		flag = 1;

	if (flag == 1) {
		for (i; i < n; i++) {
			if (s1[i] > s2[i])
				return false;
		}
	}
	else {
		for (i; i < n; i++) {
			if (s1[i] < s2[i])
				return false;
		}
	}
	return true;
}