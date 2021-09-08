#include <bits/stdc++.h>
using namespace std;

vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
	vector<int>res;

	int allSum = 0;
	for (int i = 0; i < nums.size(); i++) {
		allSum += nums[i];
	}

	int n = nums.size();
	int sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum += nums[i];
		res.push_back(nums[i]);

		if (sum > allSum - sum)
			return res;
	}
        
        vector<int>a={};
        return a;
}