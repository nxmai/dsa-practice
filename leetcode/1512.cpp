#include <bits/stdc++.h>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
        map<int, int>mp;
	for (int i = 0; i < nums.size(); i++) {
		mp[nums[i]]++;
	}

	int res = 0;
	int tmp;
	map<int, int>::iterator it = mp.begin();
	for (it; it != mp.end(); it++) {
		tmp = (*it).second;
		res += tmp * (tmp - 1) / 2;
	}
	return res;
}