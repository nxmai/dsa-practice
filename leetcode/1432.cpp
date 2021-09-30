#include <bits/stdc++.h>
using namespace std;

int maxDiff(int num) {
        string tmp = to_string(num);
	int i = 0;

	while (i < tmp.length() && tmp[i] == '9') {
		i++;
	}
	char t = tmp[i];
	for (int j = 0; j < tmp.length(); j++) {
		if (tmp[j] == t)
			tmp[j] = '9';
	}
	int a = number(tmp);

	tmp = to_string(num);
	i = 0;
	if (tmp[i] != '1') {
		char t = tmp[i];
		for (int j = 0; j < tmp.length(); j++) {
			if (tmp[j] == t)
				tmp[j] = '1';
		}
	}
	else {
		i = 1;
		while (i < tmp.length() && (tmp[i] == '0' || tmp[i] == '1'))
			i++;

		if (i < tmp.length()) {
			char t = tmp[i];
			for (int j = 0; j < tmp.length(); j++) {
				if (tmp[j] == t)
					tmp[j] = '0';
			}
		}
	}
	int b = number(tmp);

	return a - b;
    }
    
    int number(string s) {
	int res = 0;
	for (int i = 0; i < s.length(); i++) {
		res = res * 10 + int(s[i]) - 48;
	}
	return res;
}