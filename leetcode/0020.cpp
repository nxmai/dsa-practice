#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    if ((s.length() == 1))
    return 0;
	stack<char> st;
	int n = s.length();

	for (int i = 0; i < n; i++) {
		if (s[i] == '[' || s[i] == '{' || s[i] == '(')
			st.push(s[i]);
		else {
            if ((s[i] == ']' || s[i] == '}' || s[i] == ')') && st.empty() == 1)
				return false;
            
			if (s[i] == ')' && st.top() == '(')
				st.pop();
			else if (s[i] == ']' && st.top() == '[')
				st.pop();
			else if (s[i] == '}' && st.top() == '{')
				st.pop();
			else
				return false;
		}
	}
	if (st.empty() == 1)
		return true;
	return false;
}