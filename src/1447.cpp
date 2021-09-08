#include <bits/stdc++.h>
using namespace std;

vector<string> simplifiedFractions(int n) {
    if (n == 1)
    return{};

	string tmp = "";
	vector<string>res;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) == 1) {
				tmp = to_string(j) + '/' + to_string(i);
				res.push_back(tmp);
				tmp = "";
			}

		}
	}
	return res;
}
    
int gcd(int i, int j) {
	if (j == 0)
		return i;
	return gcd(j, i % j);
}