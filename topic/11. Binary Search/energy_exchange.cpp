//codeforces
#include <iostream>
#include <iomanip>
#define MAX 10000

using namespace std;

int main() {
    int n, k;
    double a[MAX];
    double sumEnergy = 0, left, right, mid, sumTransfer;

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sumEnergy += a[i];
    }

    left = 0;
    right = 1000;

    while(right - left > 1e-7){
        mid = (right + left)/2;
        sumTransfer = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > mid)
                sumTransfer += a[i] - mid;
        }

        if(mid * n < sumEnergy - sumTransfer * k / 100)
            left = mid;
        else
            right = mid;
        
    }
    cout << fixed << setprecision(9) << mid;

    return 0;

}
