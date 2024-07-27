class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26]={0};
        for(char c: magazine){
            count[c-'a']++;
        }
        for(char ch: ransomNote){
            if(count[ch-'a']--<=0){
                return false;
            }
        }
        return true;
    }
};