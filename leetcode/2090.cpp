class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res(n, -1);
        
        if(n <= 2*k)
            return res;
        
        long long int sum = 0;
        int left = 0, right = 2*k;
        int eNum = 2*k+1;
        
        for(int i = left; i <= right; i++){
            sum += nums[i];
        }
        res[k] = (floor(sum/eNum));
        right++;
        
        for(int i = k + 1; i < n - k; i++){
            sum = sum - nums[left++] + nums[right++];
            res[i] = (floor(sum/eNum));
        }
        
        return res;
        
        
    }
};