//codeforces
#include <iostream>
#include <vector>
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
    int n;
    vector<int>nums;
    cin >> n;
    input(n , nums);

    int l = 0, r = 0, count = 0;    
    int flag = 1;

    for(int i = 0; i < n - 1; i++){
        if(count == 1 && nums[i] < nums[l]){
            flag = 0;
            break;
        }
        if(count >= 2){
            flag = 0;
            break;
        }

        if(nums[i] > nums[i+1]){
            count++;
            l = i;
            while(i < n - 1 && nums[i] > nums[i+1]){
                i++;
            }
            r = i;
        }
    }
    if (count == 1 && nums[l-1] > nums[r]){
          flag = 0;
      }

    if(flag == 0){
        cout << "no";
    } else {
        cout << "yes" <<endl;
        cout << l+1 << " "<< r+1;
    }
    return 0;

}