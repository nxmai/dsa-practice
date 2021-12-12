//spoj
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    long long t;
    vector<long long>vt;

    for(int i = 0; i < n; i++){
        cin >> t;
        vt.push_back(t);
    }

    sort(vt.begin(), vt.end());

    long long left = 0, right = vt[n-1], mid;
    long long sum=0, h=0;
    while(left <= right ) {
        mid = (left + right)/2;
        sum = 0;

        for(int i = 0; i < n; i++){
            if(vt[i] > mid){
                sum += (vt[i] - mid);
            }
        }
        
        if(sum > m){
            left = mid + 1;
            if(mid > h)
                h = mid;    
        
        } else if(sum < m){
            right = mid - 1;
        } else {
            h = mid;
            break;
        }
    }

    cout << h;

    return 0;
}