#include <bits/stdc++.h>
using namespace std;

bool kLengthApart(vector<int>& nums, int k) {
    int i = 0, n = nums.size();
	while (i < n && nums[i] == 0)
		i++;

	if (i == n)
		return true;

	int dis = 0;
	i++;
	while (i < n) {
		if (nums[i] == 1) {
			if (dis < k)
				return false;
			dis = 0;
		}
		else {
			dis++;
		}
		i++;
	}

	return true;
}