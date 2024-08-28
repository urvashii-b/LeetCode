class Solution {
private:
    bool solve(int i, int j, string &pattern, string &text, vector<vector<int>> &dp){
        if(i<0 && j<0) return true;     // both exhausted - done
        if(i<0) return false;   // pattern done but string remains - false
        if(j<0){
            for(int x=0;x<=i;x++){
                if(pattern[x]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(pattern[i]==text[j] || pattern[i]=='?'){
            return dp[i][j] = solve(i-1,j-1,pattern,text,dp);
        }
        if(pattern[i]=='*'){
            return dp[i][j] = solve(i-1,j,pattern,text,dp) || solve(i,j-1,pattern,text,dp);
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(n-1,m-1,p,s,dp);
    }
};