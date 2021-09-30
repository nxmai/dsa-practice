#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
	int window = 0;
	int res;

	for (int i = n - k; i < n; i++)
		window += cardPoints[i];

	res = window;
	for (int i = 0; i < k; i++) {
		window += cardPoints[i] - cardPoints[n - k + i];
		res = max(res, window);
	}
	return res;
}