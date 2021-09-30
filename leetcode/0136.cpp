#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    map<int, int>mp;
	for (int i = 0; i < nums.size(); i++) {
		mp[nums[i]]++;
	}

	int tmp;
	for (map<int,int>::iterator i = mp.begin(); i != mp.end(); i++) {
		if ((i)->second == 1) {
			tmp = i->first;
			break;
		}
	}
	return tmp;
}