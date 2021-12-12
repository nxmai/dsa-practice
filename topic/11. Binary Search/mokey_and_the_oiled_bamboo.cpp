//uva
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, a;
    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> n;
        vector<int>vt;

        vt.push_back(0);
        for(int j = 0; j < n; j++){
            cin >> a;
            vt.push_back(a);
        }

        int l = 1, r = vt[n], mid;
        int res;
        while(l<=r){
            mid = (l + r)/2;
            int k = mid;

            bool check = true;
            for(int j = 1; j <= n; j++){
                if(vt[j] - vt[j-1] > k){
                    check = false;
                    break;
                } else {
                    if(vt[j] - vt[j-1] == k){
                        k--;
                    }
                }
            }

            if(check){
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << "Case " << i << ": " << res << endl;
    }
}