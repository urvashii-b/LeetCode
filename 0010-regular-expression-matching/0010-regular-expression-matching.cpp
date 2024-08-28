class Solution {
private:
    bool solve(string &text, string &pattern, int i, int j){
        if(j<0) return i<0;   // if path is done, and the string is also done 
        if(i<0 && j>=0){ //string exhausted but matchings left
            if(pattern[j]=='*'){
                return solve(text,pattern,i,j-2);
            }
            return false;
        }
        if(pattern[j]==text[i] || pattern[j]=='.'){
            return solve(text,pattern,i-1,j-1);
        }
        if(pattern[j]=='*'){
            if(solve(text,pattern,i,j-2)) return true;
            if(pattern[j-1]=='.' || pattern[j-1]==text[i]){
                return solve(text,pattern,i-1,j);
            }
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        return solve(s,p,n-1,m-1);
    }
};