//codeforces

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, res = 0, tmp;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;

        if(res + 15 < tmp){
            res += 15;
            break;
        } else {
            res = tmp;
        }
    }

    if(res == tmp)
        res = (res + 15 >= 90) ? 90 : res + 15; 

    cout << res;

    return 0;
}