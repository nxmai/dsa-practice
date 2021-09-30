#include <bits/stdc++.h>
using namespace std;

string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;
	if (a != 0)pq.push({ a,'a' });
	if (b != 0)pq.push({ b,'b' });
	if (c != 0)pq.push({ c, 'c' });

	char pre1 = '#';
	char pre2 = '#';
	string res = "";
	pair<int, char>t;

	while (!pq.empty()) {
		t = pq.top();
		pq.pop();
		
		if (t.second == pre1 && t.second == pre2) {
            if (pq.empty())
				return res;
			pair<int, char>t2 = pq.top();
			pq.pop();

			res += t2.second;
			pre1 = pre2;
			pre2 = t2.second;
			pq.push(t);
			if (--t2.first > 0)pq.push(t2);
		}
		else {
			pre1 = pre2;
			pre2 = t.second;
			res += t.second;
			if (--t.first > 0)pq.push(t);
		}
	}

	return res;
}