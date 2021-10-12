//codeforces

#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

int main() {
    int n;
    int Li, Ri;
    int Lmin = INT_MAX, Rmax = INT_MIN;
    int res = -1, Lres, Rres;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> Li >> Ri;
        Lmin = min(Lmin, Li);
        Rmax = max(Rmax, Ri);

        if(Li == Lmin && Ri == Rmax){
            res = i;
            Lres = Lmin;
            Rres = Rmax;    
        }
    }

    if( Lres == Lmin && Rres == Rmax )
        cout << res + 1;
    else
        cout << -1;
    
    return 0;
}