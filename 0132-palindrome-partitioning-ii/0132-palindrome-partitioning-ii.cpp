class Solution {
private:
    bool isPalindrome(int left, int right, string &s){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    int solve(string &s, int i, int n, vector<int> &dp){
        if(i==n){
            return 0;
        }
        int minCost = INT_MAX;
        if(dp[i]!=-1) return dp[i];
        for(int j=i; j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost = 1+solve(s,j+1,n,dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }
public:
    int minCut(string s) {
        // front partitioning 
        int n = s.length();
        vector<int> dp(n+1,-1);
        return solve(s,0,n,dp)-1;
    }
};