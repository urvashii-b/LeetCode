class Solution {
/*
1. RECURSION
private:
    int countPaths(int i, int j, int m, int n){
        if((i==m-1) && (j==n-1)) return 1;
        if(i>=m || j>=n) return 0;
        else return countPaths(i+1,j,m,n) + countPaths(i,j+1,m,n);
    }
public:
    int uniquePaths(int m, int n) {
        // m = rows, n = cols
        return countPaths(0,0,m,n);
    }
    
2. DP
*/
private:
    int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp){
        if((i==m-1) && (j==n-1)) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        else return dp[i][j]=countPaths(i+1,j,m,n,dp) + countPaths(i,j+1,m,n,dp);
    }
public:
    int uniquePaths(int m, int n) {
        // m = rows, n = cols
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(0,0,m,n,dp);
    }
};