#include <bits/stdc++.h>
using namespace std;

int minStartValue(vector<int>& nums) {
        int n = nums.size();
	int tmp, flag = 1;

	int res = 1 - nums[0];
	if (res <= 0)
		res = 1;

	while (1)
	{
		flag = 1;
		tmp = res;
		for (int i = 0; i < n; i++) {
			tmp += nums[i];
			if (tmp < 1) {
				i = n;
				flag = 0;
			}
		}
		if (flag == 1)
			break;
		res++;
	}
	return res;
}