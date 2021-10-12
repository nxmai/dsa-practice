//codeforces
#include <iostream>
#include <algorithm>
#include <vector>

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
    int n, a, b;
    vector<int>h;

    cin >> n >> a >> b;
    input(n, h);

    sort(h.begin(), h.end());
    cout << h[n - a] - h[b - 1];

    return 0;

}