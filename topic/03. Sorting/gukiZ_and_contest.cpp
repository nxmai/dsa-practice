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
    int n;
    vector<int>nums;
    cin >> n;
    input(n , nums);

    vector<int>res = nums;
    vector<int>arr(2001, 0);

    sort(nums.begin(), nums.end(), greater<int>());

    int prev = nums[0];
    int count = 1;
    nums[0] = 1;
    arr[prev] = 1;

    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != prev){
            prev = nums[i];
            arr[prev] = nums[i-1] + count;
            nums[i] = nums[i-1] + count;
            count = 1;
        } else {
            nums[i] = nums[i-1];
            count++;
        }
    }

    
    for(int i = 0; i < res.size(); i++){
        res[i] = arr[res[i]];
    }

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }

    return 0;
}