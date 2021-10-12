//codeforce
#include <iostream>
#include <vector>
#include <utility>

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
    int n, m, x, y;
    vector<int> A, B;
    
    cin >> n >> m >> x >> y;
    input(n, A);
    input(m, B);

    vector<pair<int,int>>res;

    int i = 0, j = 0;
    while(i < n && j < m){
        if(B[j] >= A[i] - x && B[j] <= A[i] + y){
            res.push_back(make_pair(i+1, j+1));
            A[i++] = -1;
            B[j++] = -1;
        } else if(B[j] >= A[i] - x){
            i++;
        } else if(B[j] <= A[i] + y){
            j++;
        }
    }

    cout << res.size() <<endl;
    for(vector<pair<int,int>>::iterator it = res.begin(); it != res.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}