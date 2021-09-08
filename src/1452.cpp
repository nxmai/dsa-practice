#include <bits/stdc++.h>
using namespace std;

vector<int> peopleIndexes(vector<vector<string>>& input) {
    vector<int>res;
	vector<set<string>>vt;
	set<string>tmp;

	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[i].size(); j++) {
			tmp.insert(input[i][j]);
		}
		vt.push_back(tmp);
        tmp.clear();
	}

	int flag = 1;
	for (int i = 0; i < vt.size(); i++) {
		for (int j = 0; j < vt.size(); j++) {
			if (j!=i && includes(vt[j].begin(), vt[j].end(), vt[i].begin(), vt[i].end()) == true) {
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			res.push_back(i);
		flag = 1;
	}
    return res; 
}
