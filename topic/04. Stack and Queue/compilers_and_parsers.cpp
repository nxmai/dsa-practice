//codechef
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int solve(string s){
    stack<char>st;
    int tmp = 0;
    int ans = 0;
    if(s[0] == '>')
        return 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '<'){
            st.push(s[i]);
            cnt1++;
        }
        else {
            cnt2++;
            if(!st.empty()){
                st.pop();
                tmp += 2;
            } 
            if(st.empty() && cnt1 == cnt2) {
                ans = tmp;
            }
        }
    }
    // if(st.empty()){
    //     ans = tmp;
    // }

    return ans;
}

int main() {
    int n;
    string s;
    int ans = 0;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        cout << solve(s) << endl;
    }

    

    return 0; 
}
