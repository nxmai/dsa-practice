//codeforces
#include <iostream>
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
    int n ;
    vector<int>nums;
    int seraScore = 0, dimaScore = 0;

    cin >> n;
    input(n, nums);

    int i = 0, j = n - 1;
    int flag = 0; // = 0 => sera turn

    while(i <= j) {
        if(nums[i] > nums[j]){
            if(flag == 0){
                seraScore += nums[i];
                flag = 1;
            } else {
                dimaScore += nums[i];
                flag = 0;
            }
            i++;
        } else {
            if(flag == 0){
                seraScore += nums[j];
                flag = 1;
            } else {
                dimaScore += nums[j];
                flag = 0;
            }
            j--;
        }
    }

    cout << seraScore << " " << dimaScore;

    return 0;
}