//codeforces 
#include <iostream>
#include <vector>
#include <limits.h>

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
    int n;
    vector<int>nums;

    cin >> n;
    input(n, nums);

    int j = n - 1;
    int tmp = n - 1;
    int res = 1;

    while(j >= 0 && tmp >= 0) {

        if(tmp > j) {
            res++;
        }

        if(nums[j] != 0){
            tmp = min(tmp, j - nums[j]);
        } 
        
        j--;
    }
    
    cout << res;

    return 0;
}