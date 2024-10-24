class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s=="") return 0;
        int open = 0, close = 0;
        for(char c:s){
            if(c=='('){
                open++;
            }else{
                if(open==0){
                    close++;
                }
                open= max(open-1,0);
            }
        }
        return open+close;
    }
};