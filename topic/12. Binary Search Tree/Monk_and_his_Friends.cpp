//hackerearth
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int t, n, m;
    long long a;
    cin >> t;
    while(t!=0){
        cin >> n >> m;
       set<long long>st;

        for(int i = 0; i < n; i++){
            cin >> a;
            st.insert(a);
        }
        for(int i = 0; i < m; i++){
            cin >> a;
            if(st.find(a) != st.end()){
                cout << "YES" << endl;
                //mp[a]--;
            } else {
                st.insert(a);
                cout << "NO" << endl;
            }
        }

        t--;
    }

    return 0;
}