class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string s="";
        for(char c: target){
            s+='a';
            ans.push_back(s);
            while(s.back()!=c){
                s.back()++;
                ans.push_back(s);
            }
        }
        return ans;
    }
};