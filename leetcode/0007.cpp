#include<bits/stdc++.h>
using namespace std;

int reverse(int x) {
    long long res = 0;
	int pop;

	while (x != 0) {
		pop = x % 10;
		res = res * 10 + pop;
		x /= 10;
	}
	if (res <= INT_MIN || res >= INT_MAX)
		return 0;

	return res;
}