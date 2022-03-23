class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0;
        int i = 1;
        
        while(i < nums.size() - 1){
            while(i < nums.size() - 1 && nums[i-1] == nums[i]){
                i++;
            }
            int prev = nums[i-1];
            while(i < nums.size() - 1 && nums[i] == nums[i+1]){
                i++;
            }
            if(i+1 == nums.size()){
                break;
            }
            int nxt = nums[i+1];
            
            
            if(prev > nums[i] && nxt > nums[i]){
                res++;
            } else if(prev < nums[i] && nxt < nums[i]){
                res++;
            }
            i++;
        }
        
        return res;
    }
};