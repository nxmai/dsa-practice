#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    map<int, int>sum;
	int s = 0;
	int res = 0;
	for (int i = 0; i < nums.size(); i++) {
		s += nums[i];
		if (s == k)
			res++;
		if (sum[s - k])
			res += sum[s - k];
		sum[s]++;
	}
	return res;
}