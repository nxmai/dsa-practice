#include <bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    int n;
	int tmp;
	while (stones.size() > 1) {
		sort(stones.begin(), stones.end());
		n = stones.size() - 1;
		if (stones[n] == stones[n - 1]) {
			stones.erase(stones.begin() + n - 1, stones.begin() + n + 1);
		}
		else {
			tmp = stones[n] - stones[n - 1];
			stones.erase(stones.begin() + n - 1, stones.begin() + n + 1);
			stones.push_back(tmp);
		}
		
	}
	if (stones.size() == 0)
		return 0;
	return stones[0];
}