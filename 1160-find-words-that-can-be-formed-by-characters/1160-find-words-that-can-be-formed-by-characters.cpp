class Solution {
/*
private:
    bool formed(string s, string chars){
        unordered_map<char, int> mpp;
        for(char &c: s){
            mpp[c]++;
        }
        for(char &c: chars){
            mpp[c]--;
        }
        for(auto it: mpp){
            if(it.second>0){
                return false;
            }
        }
        return true;
    }
*/
public:
    int countCharacters(vector<string>& words, string chars) {
        /*
        int n = words.size(), sum = 0;
        for(int i=0;i<n;i++){
            if(formed(words[i], chars)){
                sum+=words[i].length();
            }
        }
        return sum;
        */
        vector<int> charcnt(26,0);
        for(char &c:chars){
            charcnt[c-'a']++;
        }
        int ans = 0;
        for(string &s: words){
            vector<int> wordcnt(26,0);
            for(char &ch:s){
                wordcnt[ch-'a']++;
            }
            bool flag = true;
            for(int i=0;i<26;i++){
                if(wordcnt[i]>charcnt[i]){
                    flag = false;
                    break;
                }
            }
            if(flag==true){
                ans+= s.size();
            }
        }
        return ans;
    }
};