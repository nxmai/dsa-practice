class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        bool arr1[101] = {0};
        bool arr2[101] = {0};
        bool arr3[101] = {0};
        
        for(int i = 0; i < nums1.size(); i++) arr1[nums1[i]] = true;
        for(int i = 0; i < nums2.size(); i++) arr2[nums2[i]] = true;
        for(int i = 0; i < nums3.size(); i++) arr3[nums3[i]] = true;
        
        vector<int>res={};
        for(int i = 1; i < 101; i++){
            if((arr1[i] and arr2[i]) or (arr2[i] and arr3[i]) or (arr3[i] and arr1[i])){
                res.push_back(i);
            }
        }
        
        return res;
    }
};