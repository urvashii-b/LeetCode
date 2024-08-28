class Solution {
private:
    bool solve(string &text, string &pattern, int i, int j, vector<vector<int>> &dp){
        if(j<0) return i<0;   // if path is done, and the string is also done 
        if(j<0) return false;
        if(i<0 && j>=0){ //string exhausted but matchings left
            if(pattern[j]=='*'){
                return solve(text,pattern,i,j-2,dp);
            }
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(pattern[j]==text[i] || pattern[j]=='.'){
            return dp[i][j]=solve(text,pattern,i-1,j-1,dp);
        }
        if(pattern[j]=='*'){
            if(solve(text,pattern,i,j-2,dp)) return dp[i][j]=true;
            if(pattern[j-1]=='.' || pattern[j-1]==text[i]){
                return dp[i][j]=solve(text,pattern,i-1,j,dp);
            }
        }
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return solve(s,p,n-1,m-1,dp);
    }
};