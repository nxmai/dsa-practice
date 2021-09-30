#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2) {
        string res = "";
	int minSize = (word1.size() < word2.size()) ? word1.size() : word2.size();
	int i;
	for (i = 0; i < minSize; i++) {
		res += word1[i];
		res += word2[i];
	}
	if (minSize == word1.size())
	{
		for (i; i < word2.size(); i++) {
			res += word2[i];
		}
	}
	else {
		for (i; i < word1.size(); i++) {
			res += word1[i];
		}
	}
	return res;
}