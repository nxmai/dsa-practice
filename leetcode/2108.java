class Solution {
    public String firstPalindrome(String[] words) {
        for(int i = 0; i < words.length; i++){
            if(palindrom(words[i])){
                return words[i];
            }
        }
        return "";
    }
    
    public boolean palindrom(String word){
        int n = word.length();
        for(int i = 0; i < (n / 2); i++){
            if(word.charAt(i) != word.charAt(n - 1 - i)){
                return false;
            }
        }
        return true;
    }
}