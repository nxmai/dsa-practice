#include <bits/stdc++.h>
using namespace std;

int minNumberOfFrogs(string croakOfCroaks) {
        int c = 0, r = 0, o = 0, a = 0, k = 0;
	int res = 0;

	for (int i = 0; i < croakOfCroaks.length(); i++) {
		if (croakOfCroaks[i] == 'c')
			c++;
		if (croakOfCroaks[i] == 'r')
			r++;
		if (croakOfCroaks[i] == 'o')
			o++;
		if (croakOfCroaks[i] == 'a')
			a++;
		if (croakOfCroaks[i] == 'k')
			k++;

		if (c >= r && r >= 0 && o >= a && a >= k)
			res = max(res, c);
		else
			return -1;

		if (croakOfCroaks[i] == 'k') {
			c--; r--; o--; a--; k--;
		}
	}
	if (c == 0 && r == 0 && o == 0 && a == 0 && k == 0)
		return res;
	return -1;
}