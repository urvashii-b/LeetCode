class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int open=0;
        for(char c:s){
            if(c=='(' && open++>0) ans+=c;
            if(c==')' && open-->1) ans+=c;
        }
        return ans;
    }
};