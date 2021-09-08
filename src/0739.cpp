#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    stack<int>st;
	int n = T.size() - 1;
	vector<int>res(n+1, 0);

	for (int i = n; i >= 0; i--) {
		while (!st.empty() && T[i] >= T[st.top()]) st.pop();
		res[i] = st.empty() ? 0 : st.top() - i;
		st.push(i);
	}
	return res;
}