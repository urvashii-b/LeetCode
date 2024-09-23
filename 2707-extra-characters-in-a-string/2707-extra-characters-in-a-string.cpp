class Solution {
private:
    int solve(int i, int &n, string& s, unordered_set<string>& st){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int res = 1 + solve(i+1,n,s,st);
        for(int j=i; j<n; j++){
            string cur = s.substr(i,j-i+1);
            if(st.count(cur)){
                res = min(res, solve(j+1,n,s,st));
            }
        }
        return dp[i] = res;
    }
public:
    int dp[51];
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        memset(dp,-1,sizeof(dp));
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        return solve(0, n, s, st);
    }
};