#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string>res;
	bin(res, "a", n);
	bin(res, "b", n);
	bin(res, "c", n);

	sort(res.begin(), res.end());
	if (k > res.size())
		return "";
	else
		return res[k - 1];
    }
    
private:
    void bin(vector<string>&ans, string s, int n) {
	if (s.length() == n) {
		ans.push_back(s);
		return;
	}

	if (s[s.length() - 1] == 'a') {
		bin(ans, s += "b", n);
		s.erase(s.end() - 1, s.end());
		bin(ans, s += "c", n);
	}
	else if (s[s.length() - 1] == 'b') {
		bin(ans, s += "a", n);
		s.erase(s.end() - 1, s.end());
		bin(ans, s += "c", n);
	}
	else if (s[s.length() - 1] == 'c') {
		bin(ans, s += "b", n);
		s.erase(s.end() - 1, s.end());
		bin(ans, s += "a", n);
	}

	return;
}
};