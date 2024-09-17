class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        unordered_map<string, int> freq;
        string word="";
        for(char c: s1){
            if(c==' '){
                freq[word]++;
                word="";
            }else{
                word+=c;
            }
        }
        freq[word]++;
        word="";
        for(char c: s2){
            if(c==' '){
                freq[word]++;
                word="";
            }else{
                word+=c;
            }
        }
        freq[word]++;
        word="";
        for(auto& it: freq){
            if(it.second == 1){
                res.push_back(it.first);
            }
        }
        return res;
    }
};