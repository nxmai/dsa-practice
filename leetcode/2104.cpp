#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        vector<int> maxA = nums;
        vector<int> minA = nums;
        
        int len = nums.size();
        long long res = 0;
        
        while(len > 0){
            for(int i = 0; i < len - 1; i++){
                maxA[i] = max(maxA[i], maxA[i+1]);
                minA[i] = min(minA[i], minA[i+1]);
                res += maxA[i] - minA[i];
            }
            len--; 
        }
        
        return res;
    }
};