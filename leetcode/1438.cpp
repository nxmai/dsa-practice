#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
    multiset<int>ms;
	int n = nums.size();
	int i = 0, j;

	for (j = 0; j < n;j++) {
		ms.insert(nums[j]);
		if (*ms.rbegin() - *ms.begin() > limit)
			ms.erase(ms.find(nums[i++]));
	}
	return j - i;
}