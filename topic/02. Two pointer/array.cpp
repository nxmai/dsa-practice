//codeforces
#include <iostream>
#include <vector>
#include <map>

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
    int n, k;
    vector<int>nums;
    map<int,int>mp;

    cin >> n >> k;
    input(n, nums);

    int i = 0, j = 0;
    int flag = -1;

    while(j < n){
        mp[nums[j]]++;
        if(mp.size() == k){
            while (mp[nums[i]] >= 2){
                mp[nums[i]]--;
                i++;
            } 
            flag = 0;
            break;
        } else{
            j++;
        }
    }

    if(flag == -1)
        cout << -1 << " " << -1;
    else
        cout << i+1 << " " << j+1;

    
    return 0;
}



//ask TA  for all of the answer or for the smallest length