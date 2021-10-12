//codeforce

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, tmp;
    vector<int> arrN, arrM;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        arrN.push_back(tmp);
    }
    for(int i = 0; i < m; i++){
        cin >> tmp;
        arrM.push_back(tmp);
    }

    int cnt = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j < m){
            if(arrM[j] >= arrN[i]){
                cnt++;
                i++;
            }
            j++;
        }
    }

    if(n - cnt < 0 )
        cout << 0;
    else
        cout << n - cnt;


    return 0;

}