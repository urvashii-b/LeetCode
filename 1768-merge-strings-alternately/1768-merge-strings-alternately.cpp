class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int i=0;
        while(i<word1.length() || i<word2.length()){
            if(i<word1.length()){
                res+=word1[i];
            }
            if(i<word2.length()){
                res+=word2[i];
            }
            i++;
        } 
        return res;
    }
};