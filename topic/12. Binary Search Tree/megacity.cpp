//codeforces
#include <iostream>
#include <map>
#include <math.h>
#include <iomanip> 

using namespace std;

int main() {
    int n, s;
    int x, y, k;
    map<int, int>mp;

    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> x >> y >> k;
        mp[pow(x, 2) + pow(y, 2)] += k;
    }

    bool res = false;
    map<int, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++){
        s += it->second;
        if(s >= 1000000){
            res = true;
            break;
        }
    }

    if(res){
        double ans;
        ans = sqrt(it->first);
        cout << fixed << setprecision(7) << ans;
    } else {
        cout << -1;
    }

    return 0;
}