#include <bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<int>tmp;
	tmp = candies;
	sort(tmp.begin(), tmp.end());

	int greatest = tmp[tmp.size() - 1];
	vector<bool>res;

	for (int i = 0; i < candies.size(); i++) {
		if (candies[i] + extraCandies >= greatest)
			res.push_back(true);
		else
			res.push_back(false);
	}

	return res;
}