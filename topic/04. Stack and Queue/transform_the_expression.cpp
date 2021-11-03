//spoj

#include <iostream>
#include <stack>
#include <queue>
#include <map>

using namespace std;


string postfix(string s, map<char,int>prior){
    stack<char>st;
    queue<char>qu;
    string ans = "";

    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            ans += s[i];

        } else if(s[i] == '('){
            st.push(s[i]);

        } else if(s[i] == ')'){
           
            while(st.empty() == false && st.top() != '('){
                //cout << "loop" << st.top() << "  ";
                ans += st.top();
                st.pop();
            }
            st.pop();

        } else if(st.size() != 0 && st.top() != '(' && prior[s[i]] < prior[st.top()]){
            while(st.empty() == false && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);

        } else {
            st.push(s[i]);
        }
    }

    return ans;
}

int main() {
    int n;
    

    map<char, int>prior;
    prior.insert({'+', 1});
    prior.insert({'-', 2});
    prior.insert({'*', 3});
    prior.insert({'/', 4});
    prior.insert({'^', 5});

    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        cout << postfix(s, prior) << endl;
    }

    return 0;

}
