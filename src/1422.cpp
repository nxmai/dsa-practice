#include <bits/stdc++.h>
using namespace std;

int maxScore(string s) {
        map<int, pair<int, int>>mp;

	if (s[0] == '0')
		mp[0] = { 1,0 };
	else
		mp[0] = { 0,1 };

	pair<int, int>pre = mp[0];
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '0')
			pre.first++;
		else
			pre.second++;
		mp[i] = pre;
	}

	int i1 = mp[s.length() - 1].second;
	int i0 = mp[s.length() - 1].first;

	int res = -1;
	for (int i = 0; i < s.length() - 1; i++) {
		res = max(res, mp[i].first - mp[i].second + i1);
	}
	return res;
}