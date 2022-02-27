class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = 0;
        int tmp = 0;
        for(int i = 0; i < sentences.size(); i++){
            for(int j = 0; j < sentences[i].length(); j++){
                if(sentences[i][j] == ' '){
                    tmp++;
                }
            }
            if(tmp > res){
                res = tmp;
                
            }
            tmp = 0;
        }
        return res + 1;
    }
};