//codeforces
#include <iostream>
#include <vector>
#include <functional>
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
    int k;
    vector<int>a;

    cin >> k;
    input(12, a);

    sort(a.begin(), a.end(), greater<int>());

    int i = 0;
    int count = 0;
    while(i < 12 && k > 0){
        k -= a[i];
        count++;
        i++;
    }
    if(k > 0)
        cout << -1;
    else
        cout << count;

    return 0;
}