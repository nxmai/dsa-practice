#include <bits/stdc++.h>
using namespace std;

int numOfWays(int n) {
        int Mod = (int)1e9 + 7;
	long color123 = 6;
	long color121 = 6;

	long tmp;
	for (int i = 2; i <= n; i++) {
		tmp = color123;

		color123 = (2 * color123 + 2 * color121) % Mod;
		color121 = (2 * tmp + 3 * color121) % Mod;
	}

	return (color123 + color121) % Mod;
}
