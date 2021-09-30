#include <bits/stdc++.h>
using namespace std;

int numSub(string s) {
        map<long int, long int>mp;

	int i = 0;
	int count;
	while (i < s.length()) {
		count = 0;
		if (s[i] == '1') {
			while (s[i] == '1') {
				count++;
				i++;
			}
			mp[count]++;
		}
		else
			i++;
	}

	map<long int, long int>::iterator it = mp.begin();
	long int res = 0;
	long int tmp1, tmp2;

	for (it; it != mp.end(); it++) {
		tmp1 = (*it).first;
        tmp2 = (*it).second;
		res += ((tmp1 + 1) * tmp1 / 2)*tmp2;
        res%=1000000007;
	}
	return res;
}