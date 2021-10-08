#include <iostream>

using namespace std;

int longest(string a, int k, char c)
    {
        int n = a.length();
        int cnt = 0;
        int l = 0;
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] == c)
                cnt++;
            
            while (cnt > k) {
                if (a[l] == c)
                    cnt--;
                l++;
            }

            max_len = max(max_len, i - l + 1);
        }

        return max_len;
    }
    
    int maxConsecutiveAnswers(string key, int k) {
        int res = max(longest(key, k, 'F'), longest(key, k, 'T'));
        
        return res;
    }