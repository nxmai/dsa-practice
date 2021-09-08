#include <bits/stdc++.h>
using namespace std;

vector<string> stringMatching(vector<string>& words) {
        
        int n = words.size();
	vector<string>ans;
	vector<int>tick(n, 0);

	for (int i = 0; i < n; i++) {
		if (tick[i] == 0) {
			for (int j = 0; j < n; j++) {
				if (j != i && tick[j] == 0 && words[i].find(words[j]) != string::npos) {
					ans.push_back(words[j]);
					tick[j] = 1;
				}
			}
		}
	}

	return ans;
}