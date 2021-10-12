//codeforces
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input(int n, vector<int>&arr){
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    return;
}

int main() {
    int n, x;
    vector<int> c;
    cin >> n >> x;

    input(n, c);

    sort(c.begin(), c.end());
    int i = 0;
    long long res = 0;

    while(i < n){
        res += 1LL*x*c[i];
        if(x != 1){
            x--;
        }
        i++;
    }

    cout << res;
    return 0;
    
}