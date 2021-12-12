//hackerearth
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    set<long long> prices;
    set<long long>::iterator it;
    
    long long s, res = 10000000000000001;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        it = prices.upper_bound(s);
        if(it != prices.end()){
            long long loss = *it - s;
            res = min(res, loss);
        }
        prices.insert(s);
    }
    cout << res;
    return 0;
}