//codeforces

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

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
    int n, w;
    vector<int>nums;
    cin >> n >> w;
    input(2*n , nums);

    sort(nums.begin(), nums.end());

    float girlCup, boyCup;
    if(nums[0] < (nums[n]*1.0 / 2)){
        girlCup = nums[0];
        boyCup = nums[0]*2;
    } else{
        girlCup = nums[n]*1.0 / 2;
        boyCup = nums[n];
    }

    float res = boyCup*n + girlCup*n;
    if(res > w*1.0){
        cout << w;
    } else{
        cout << fixed;
        cout << res;
    }
    

    return 0;

}