#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>>res;
	int n = strs.size();
	string s;

	unordered_map<string, vector<string>>mp;
	for (auto i:strs)
	{
		s = i;
		sort(s.begin(), s.end());
		mp[s].push_back(i);
	}

	for (auto i : mp) {
		res.push_back(i.second);
	}

	return res;
}