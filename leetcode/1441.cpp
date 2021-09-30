#include <bits/stdc++.h>
using namespace std;

vector<string> buildArray(vector<int>& target, int k) {
    vector<string>res;
	int n = target.size();

	int num = 1;
	int i = 0;

	while (i < n) {
		if (num != target[i]) {
			res.push_back("Push");
			res.push_back("Pop");
			num++;
		}
		else {
			res.push_back("Push");
			i++;
			num++;
		}
	}
	return res;
}