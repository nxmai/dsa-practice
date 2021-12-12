class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sumRolls = 0;
        for(int i = 0; i < rolls.size(); i++){
            sumRolls += rolls[i];
        }
        
        int sum = (n + rolls.size())*mean - sumRolls;
        
        if(sum > 6*n || sum < n) return {};
        
        int floorNum = (sum / n);
        int surPlus = sum - floorNum * n;
        
        vector<int> res;
        for(int i = 0; i < surPlus; i++){
            res.push_back(floorNum + 1);
        }
        for(int i = 0; i < n - surPlus; i++){
            res.push_back(floorNum);
        }
        
        return res;
    }
};