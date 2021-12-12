//uva
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double f(double p, double q, double r, double s, double t, double u, double x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main() {
    double p, q, r, s, t, u;

    while(cin >> p >> q >> r >> s >> t >> u){
        double lo = 0.00;
        double hi = 1.00;

        if(f(p, q, r, s, t, u, 1.0) > 1e-9 || p + r + u < 0){
            cout << "No solution" << endl;
            continue;
        }

        for(int i = 0; i < 500; i++){
            double x = (lo + hi)/2;
            double F = f(p, q, r, s, t, u, x);

            if(F > 0)
                lo = x;
            else 
                hi = x;
        }

        cout << fixed << setprecision(4) << lo << endl;
    }

    return 0;
}