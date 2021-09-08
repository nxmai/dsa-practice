#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.length();
	int len2 = text2.length();

	vector<vector<int>>DP;
	DP.resize(len1 +1, vector<int>(len2 +1, 0));

	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			if (i == 0 || j == 0)
				DP[i][j] = 0;
			else if (text1[i - 1] == text2[j - 1])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}
	return DP[len1][len2];
}