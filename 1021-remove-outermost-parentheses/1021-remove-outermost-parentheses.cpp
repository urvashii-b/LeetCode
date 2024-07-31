class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int open = 0;
        for(char c:s){
            if(c=='(' && open++>0) res+=c;
            if(c==')' && open-->1) res+=c;
        }
        return res;
    }
};