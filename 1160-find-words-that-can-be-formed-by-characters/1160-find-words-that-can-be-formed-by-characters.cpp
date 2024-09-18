class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        /*
        
        lowercase English letters - use vector of size 26 OR map
        
        */
        vector<int> charCnt(26,0);
        for(char& c: chars){
            charCnt[c-'a']++;
        }
        int res = 0;
        for(string& word: words){
            vector<int> wordCnt(26,0);
            for(char& c: word){
                wordCnt[c-'a']++;
            }
            bool ok = true;
            for(int i=0; i<26; i++){
                if(wordCnt[i]>charCnt[i]){
                    ok = false;
                    break;
                }
            }
            if(ok==true){
                res+=word.length();
            }
        }
        return res;
    }
};