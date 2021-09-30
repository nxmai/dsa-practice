#include <bits/stdc++.h>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    int Xor = 0, missing = nums.size(), dup = 0;
	for (int num : unordered_set<int>(nums.begin(), nums.end())) {
		Xor ^= num;
	}

	for (int i = 0; i < nums.size(); i++) {
		dup ^= nums[i];
	}

	for (int i = 1; i < nums.size(); i++) {
		missing ^= i;
	}

	return { dup ^ Xor, missing ^ Xor };
}