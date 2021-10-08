#include <iostream>
#include <unordered_map>

using namespace std;
int characterReplacement(string s, int k) {
        int max_len = 0;
        int max_cnt_window = 0;
        
        unordered_map<int, int> count;
        int left = 0;
        for(int right = 0; right < s.length(); right++){
            count[s[right]]++;
            
            max_cnt_window = max(max_cnt_window, count[s[right]]);
            if(right - left + 1 - max_cnt_window > k){
                count[s[left]]--;
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }