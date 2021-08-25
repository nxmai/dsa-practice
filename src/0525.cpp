#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {
    int sum = 0;
	int maxL = 0;
	map<int, int>count;
	count[0] = -1;

	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i] ? 1 : -1;
		if (count.find(sum) != count.end()) {
			maxL = max(maxL, i - count[sum]);
		}
		else
			count[sum] = i;
	}
	return maxL;
}