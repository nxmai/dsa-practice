#include <bits/stdc++.h>
using namespace std;

string entityParser(string text) {
        string ans = "";
	int i = 0;
	int n = text.length();

	while (i < n)
	{
		if (text[i] == '&') {
			i++;
			if (text[i] == 'q' && text[i + 1] == 'u' && text[i + 2] == 'o' && text[i + 3] == 't' && text[i + 4] == ';') {
				ans += '"';
				i += 5;
			}
			else if (text[i] == 'a') {
				i++;
				if (text[i] == 'p' && text[i + 1] == 'o' && text[i + 2] == 's' && text[i + 3] == ';') {
					ans += "'";
					i += 4;
				}
				else if (text[i] == 'm' && text[i + 1] == 'p' && text[i + 2] == ';') {
					ans += "&";
					i += 3;
				}
				else {
					ans += "&a";

				}
			}
			else if (text[i] == 'g' && text[i + 1] == 't' && text[i + 2] == ';') {
				ans += ">";
				i += 3;
			}
			else if (text[i] == 'l' && text[i + 1] == 't' && text[i + 2] == ';') {
				ans += "<";
				i += 3;
			}
			else if (text[i] == 'f' && text[i + 1] == 'r' && text[i + 2] == 'a' && text[i + 3] == 's' && text[i + 4] == 'l' && text[i + 5] == ';') {
				ans += "/";
				i += 6;
			}
			else {
				ans += "&";
			}

		}
		else
		{
			ans += text[i];
			i++;
		}
	}

	return ans;
}