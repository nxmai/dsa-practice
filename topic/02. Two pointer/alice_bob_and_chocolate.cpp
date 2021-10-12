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

int main () {
    int n;
    vector<int>nums;

    cin >> n;
    input(n, nums);

    int i = 0, j = n - 1;
    int aliceCount = 1, bobCount = 1;
    int aliceSum = nums[i], bobSum = nums[j];
    int check = 2;

    while (check < n){
        if(aliceSum <= bobSum){
            i++;
            aliceSum += nums[i];
            aliceCount++;
        } else {
            j--;
            bobSum += nums[j];
            bobCount++;
        } 
        check++;
    }
    cout << aliceCount << " " << bobCount;

    return 0;
}