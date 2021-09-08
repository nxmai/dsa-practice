#include <bits/stdc++.h>
using namespace std;

bool isprefix(string s1, string s2) {
	int n1 = s1.length(), n2 = s2.length();
	if (n1 > n2)
		return false;
	for (int i = 0; i < n1; i++)
		if (s1[i] != s2[i])
			return false;
	return true;
}
    
int isPrefixOfWord(string sentence, string searchWord) {
    vector<string>result;
	istringstream iss(sentence);
	for (string sentence; iss >> sentence; )
		result.push_back(sentence);

	
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
		if (isprefix(searchWord, result[i]) == 1) {
			return i + 1;
		}
	}
	return -1;
}