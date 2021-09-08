#include <bits/stdc++.h>
using namespace std;

string arrangeWords(string text) {
        text += ' ';
	text[0] = ::tolower(text[0]);
	map<int, vector<string>>mp;

	int count = 0;
	int i = 0;
	string tmp = "";

	while (i < text.length()) {
		if (text[i] != ' ') {
			tmp += text[i];
			count++;
		}
		else {
			mp[count].push_back(tmp);
			tmp = "";
			count = 0;
		}
		i++;
	}

	string res = "";
	map<int, vector<string>>::iterator it = mp.begin();

	for (it; it != mp.end(); it++) {
		for (int i = 0; i < it->second.size(); i++) {
			res += it->second[i];
			res += ' ';
		}
	}

	res[0] = ::toupper(res[0]);
        
	res.erase(res.end() - 1);
	return res;
}
