#include <bits/stdc++.h>
using namespace std;

bool backspaceCompare(string S, string T) {
    int n = S.length();
	int i = 0;
	int flag = 1;
	while (i < n)
	{
		if (S[i] == '#' && i >= 1)
		{
			S.erase(S.begin() + i - 1, S.begin() + i + 1);
			i -= 1;
			flag = 0;
			n -= 2;
		}
		if (i == 0 && S[i] == '#')
		{
			S.erase(S.begin());
			flag = 0;
			n -= 1;
		}
		if (flag == 1)
			i++;
		flag = 1;
	}

	n = T.length();
	i = 0;
	flag = 1;
	while (i < n)
	{
		if (T[i] == '#' && i >= 1)
		{
			T.erase(T.begin() + i - 1, T.begin() + i + 1);
			i -= 1;
			flag = 0;
			n -= 2;
		}
		if (i == 0 && T[i] == '#')
		{
			T.erase(T.begin());
			flag = 0;
			n -= 1;
		}
		if (flag == 1)
			i++;
		flag = 1;
	}

	if (S.compare(T) == 0)
		return 1;
	return 0;
}