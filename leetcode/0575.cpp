#include <bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int>& candyType) {
        unordered_set<int>st(candyType.begin(), candyType.end());
	//for (int i = 0; i < candyType.size(); i++) {
	//	st.insert(candyType[i]);
	//}
	return candyType.size() / 2 <= st.size() ? candyType.size() / 2 : st.size();
    }