//uva
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q, t;
    vector<int>vt;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        vt.push_back(t);
    }

    cin >> q;
    vector<int>::iterator lower, upper;
    int low;

    for(int i = 0; i < q; i++){
        cin >> t;
        low = -1;
        for(int j = n-1; j >=0; j--){
            if(vt[j] < t){
                low = vt[j];
                break;
            }
        }

        lower = lower_bound(vt.begin(), vt.end(), low);
        upper = upper_bound(vt.begin(), vt.end(), t);

        if( low == -1 || vt[lower-vt.begin()] == t)
            cout << "X ";
        else   
            cout << vt[lower-vt.begin()] << " ";

        if(upper == vt.end())
            cout << "X" << endl;
        else   
            cout << vt[upper-vt.begin()] << endl;
    }

    return 0;
}