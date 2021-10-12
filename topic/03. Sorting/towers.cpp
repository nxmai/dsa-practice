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

    sort(nums.begin(), nums.end());

    int count = 1;
    int height = 1;
    int maxHei = 1;

    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != nums[i-1]){
            count++;
            maxHei = max(maxHei, height);
            height = 1;
        } else {
            height++;
        }
    }
  	maxHei = max(maxHei, height);
    cout << maxHei << " " << count;

    return 0;
}