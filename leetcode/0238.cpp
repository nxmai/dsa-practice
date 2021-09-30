#include <bits/stdc++.h>
using namespace std;


vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
	vector<int>L(n, 0);
	vector<int>R(n, 0);

	L[0] = 1;
	for (int i = 1; i < n; i++) {
		L[i] = L[i - 1] * nums[i - 1];
	}
	R[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		R[i] = R[i + 1] * nums[i + 1];
	}

	nums.clear();
	for (int i = 0; i < n; i++) {
		nums.push_back(L[i] * R[i]);
	}
	return nums;
}