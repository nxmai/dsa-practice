#include <bits/stdc++.h>
using namespace std;

string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
	
	map<string, int>mp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= 1; j++) {
			mp[paths[i][j]]++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (mp[paths[i][1]] == 1)
			return paths[i][1];
	}
	return "";
}