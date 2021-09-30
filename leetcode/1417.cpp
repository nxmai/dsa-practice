
#include <bits/stdc++.h>
using namespace std;

string reformat(string s) {
        int n = s.length();
	vector<char>num;
	vector<char>str;

	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			num.push_back(s[i]);
		else if (s[i] >= 'a' && s[i] <= 'z')
			str.push_back(s[i]);
	}

	string res = "";
	if (num.size() == str.size() + 1 || num.size() == str.size()) {
		for (int i = 0; i < str.size(); i++) {
			res += num[i];
			res += str[i];
		}
		if (num.size() == str.size() + 1)
			res += num[num.size() - 1];
	}
	else if (num.size() + 1 == str.size()) {
		for (int i = 0; i < num.size(); i++) {
			res += str[i];
			res += num[i];
		}
		res += str[str.size() - 1];
	}
	else
		res = "";

	return res;
}