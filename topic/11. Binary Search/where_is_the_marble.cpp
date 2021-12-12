//uva
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, q;
    int t;
    vector<int>vt;

    cin >> n >> q;
    int cnt = 1;
    while(n!=0 && q!=0){
        vt.clear();
        for(int i = 0; i < n; i++){
            cin >> t;
            vt.push_back(t);
        }

        sort(vt.begin(), vt.end());
        vector<int>::iterator low_value;
        cout << "CASE# " << cnt << ":" << endl;
        for(int i = 0; i < q; i++){
            cin >> t;
            low_value = lower_bound(vt.begin(), vt.end(), t);
            if(low_value != vt.end() && vt[low_value - vt.begin()] == t){
                cout << t << " found at " << low_value - vt.begin() + 1 << endl;
            } else {
                cout << t << " not found" << endl;
            }
        }
        cnt++;
        cin >> n >> q;
    }
}