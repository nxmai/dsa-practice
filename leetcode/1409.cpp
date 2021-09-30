#include <bits/stdc++.h>
using namespace std;

vector<int> processQueries(vector<int>& queries, int m) {
        vector<int>P;
	for (int i = 1; i <= m; i++)
		P.push_back(i);

	int n = queries.size();
	vector<int>ans;
	vector<int>::iterator it;
	int index, tmp;

	for (int i = 0; i < n; i++) {
		it = find(P.begin(), P.end(), queries[i]);
		if (it != P.end()) {
			index = distance(P.begin(), it);
			ans.push_back(index);


			tmp = P[index];
			for (int j = index; j > 0; j--) {
				P[j] = P[j - 1];
			}
			P[0] = tmp;
		}
	}
	return ans;
}