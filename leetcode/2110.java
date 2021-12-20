class Solution {
    public long getDescentPeriods(int[] prices) {
        long ans = prices.length;
        int i = 0, j = 1;
        int n = prices.length;
        
        while(i < n && j < n){
            long cnt = 1;
            while(j < n && prices[j-1] == prices[j] + 1){
                cnt++;
                j++;
            }
            
            if(cnt != 1){
                cnt--;
                ans += cnt + (cnt*(cnt-1))/2; 
            }
            i = j;
            j++;
        }
        
        return ans;
    }
}