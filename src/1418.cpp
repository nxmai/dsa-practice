#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        int row = orders.size();
	int col = 3;

	map<int, map<string, int>>mp;
	vector<vector<string>>res;
	res.resize(1);
	set<string>name;
	res[0].push_back("Table");

	for (int i = 0; i < row; i++) {
		name.insert(orders[i][2]);
		mp[number(orders[i][1])][orders[i][2]]++;
	}

	for (auto i : name)
		res[0].push_back(i);

	int col1 = res[0].size();

	vector<string>tmp;
	map<string, int>::iterator m;

	for (auto it : mp)
	{
		tmp.push_back(to_string(it.first));
		for (int i = 1; i < col1; i++) {
			m = it.second.find(res[0][i]);
			if (m == it.second.end())
				tmp.push_back("0");
			else
				tmp.push_back(to_string(m->second));
		}
		res.push_back(tmp);
		tmp.clear();
	}

	return res;
    }
    
    
private:
    int number(string s)
{
	int n = s.length();
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = res * 10 + (int)s[i] - 48;
	}
	return res;
}
};