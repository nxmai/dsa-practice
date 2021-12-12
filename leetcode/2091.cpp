class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int imin=0, imax=0, nmin=nums[0], nmax=nums[0];
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(nums[i] > nmax){
                nmax=nums[i];
                imax=i;
            }
            if(nums[i] < nmin){
                nmin=nums[i];
                imin=i;
            }
        }
        
        imin++; imax++;
        
        int res;
        if(imin != imax){
            if(imin < imax){
                res=min(imax, min(n-imin+1, imin+n-imax+1));
            }else{
                res=min(imin, min(n-imax+1, imax+n-imin+1));
            }
        }
        else{
            res=imin;
        }
        return res;
    }
};