class Solution {
public:
    string removeOuterParentheses(string s) {
        /*
                "(  (   )   (   )   )   (   (   )   )"
after encounter: 1  2   1   2   1   0   1   2   1   0
        */
        string ans = "";
        int use = 0;
        for(char c:s){
            if(c=='(' && use++>0){
                ans+=c;
            }
            if(c==')' && use-->1){
                ans+=c;
            }   
        }
        return ans;
    }
};