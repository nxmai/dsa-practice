//hackkerearth
#include <iostream>
#include <set>

using namespace std;

int main() {
    int t, n, x, a;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n >> x;
        set<int>s;
        for(int j = 0; j < n; j++){
            cin >> a;
            s.insert(a);
        }

        if(s.size() == x)
            cout << "Good" << endl;
        else if(s.size() > x)
            cout << "Average" << endl;
        else 
            cout << "Bad" << endl;
    }

    return 0;
}