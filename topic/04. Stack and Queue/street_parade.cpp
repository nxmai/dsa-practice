//spoj
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    int tmp;
    int last = 1;
    stack<int>st;
    
    cin >> n;
    while(n != 0){
        for(int i = 0; i < n ; i++){
            cin >> tmp;
            if(tmp == last){
                last++;
            } else {
                while(st.empty() == false && st.top() == last){
                    last++;
                    st.pop();
                }
                st.push(tmp);
            }
        }
        while(st.empty() == false && st.top() == last){
            last++;
            st.pop();
        }

        if(last == n+1){
            cout << "yes" << endl;
        }else {
            cout << "no" << endl;
        }
        cin >> n;
      	last = 1;
    }
    
    return 0;

}
