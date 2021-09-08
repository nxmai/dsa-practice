#include <bits/stdc++.h>
using namespace std;

string maximumNumber(string num, vector<int>& change) {
    string ans = "";
    
    for(int i = 0; i < num.length(); i++){
        if(change[(int)num[i] - 48] > ((int)num[i] - 48)){
            while (i < num.length() && change[(int)num[i] - 48] > ((int)num[i] - 48)){
                ans += to_string(change[(int)num[i] - 48]);
                i++;
            }
            
            while(i < num.length()){
                ans += num[i];
                i++;
            }
            break;
        } else {
            ans += num[i];
        }
    }
    
    string ans1 = "";
    
    for(int i = 0; i < num.length(); i++){
        if(change[(int)num[i] - 48] >= ((int)num[i] - 48)){
            while (i < num.length() && change[(int)num[i] - 48] >= ((int)num[i] - 48)){
                ans1 += to_string(change[(int)num[i] - 48]);
                i++;
            }
            
            while(i < num.length()){
                ans1 += num[i];
                i++;
            }
            break;
        } else {
            ans1 += num[i];
        }
    }
    
    if(ans1 > ans)
        return ans1;
    return ans;
}