class Solution {
public:
    int minimumMoves(string s) {
        int cnt = 0;
        int i = 0, n = s.length();
        
        
        while(i < n){
            int j = 0;
            int flag = 0;
            
            while(s[i] == 'O' && i < n){
                i++;
            }
            
            while(j < 3 && i < n){
                if(s[i] == 'X'){
                    flag = 1;
                }
                i++;
                j++;
            }
            if(flag == 1){
                cnt++;
            }
        }
        return cnt;
    }
};