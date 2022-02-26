class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        
        for(int i = 0; i < nums.size(); i++){
            q.push({nums[i], i});
            if(q.size() > k){
                q.pop();
            }
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qi;
        while(!q.empty()){
            qi.push({q.top().second, q.top().first});
            q.pop();
        }
        
        vector<int> res;
        while(!qi.empty()){
            res.push_back(qi.top().second);
            qi.pop();
        }
        
        return res;
        
    }
};