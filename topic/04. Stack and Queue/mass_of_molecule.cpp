//spoj
#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    stack<int>st;
    map<char, int>mp;
    mp.insert({'(', -1});
    mp.insert({'C', 12});
    mp.insert({'H', 1});
    mp.insert({'O', 16});
    int ans = 0;
    int tmp = 0;

    s = '(' + s + ')';

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == 'C' || s[i] == 'H' || s[i] == 'O') {
            st.push(mp[s[i]]);
        }   
            
        else if(s[i] >= '2' && s[i] <= '9' && s[i-1] != ')'){
            st.push((int)s[i] - 48);
        }
            
        else if (s[i] == ')'){
            tmp = 0;
            while(st.top() != -1){
                int val = st.top();
                st.pop();
                if(val >= 2 && val <= 9 && st.top() != -1){
                    tmp += val * st.top();
                    st.pop();
                } else {
                    tmp += val;
                }
            }
            st.pop(); //pop (
            if( i+1 < s.length() && s[i+1] >= '2' && s[i+1] <= '9'){
                tmp = ((int)s[i+1] - 48) * tmp;
                i++;
            } 
            st.push(tmp);
        }
    }

    cout << tmp;
    return 0;
}